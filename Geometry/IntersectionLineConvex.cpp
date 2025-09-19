int TangentDir(vector<P> &C, P dir) {
	return cyc_tsearch(size(C), [&](int a, int b) {
			return (dir ^ C[a]) > (dir ^ C[b]); 
			});
}
#define cmpL(i) ori(a, C[i], b)
pii lineHull(P a, P b, vector<P> &C) {
	int A = TangentDir(C, a - b);
	int B = TangentDir(C, b - a);
	int n = size(C);
	if (cmpL(A) < 0 || cmpL(B) > 0) 
		return pii(-1, -1); // no collision
	auto gao = [&](int l, int r) {
		for (int t = l; (l + 1) % n != r; ) {
			int m = ((l + r + (l < r ? 0 : n)) / 2) % n;
			(cmpL(m) == cmpL(t) ? l : r) = m;
		}
		return (l + !cmpL(r)) % n;
	};
	pii res = pii(gao(B, A), gao(A, B)); // (i, j)
	if (res.first == res.second) // touching the corner i
		return pii(res.first, -1);
	if (!cmpL(res.first) && !cmpL(res.second)) // along side i, i+1 
		switch ((res.first - res.second + n + 1) % n) {
			case 0: return pii(res.first, res.second);
			case 2: return pii(res.second, res.second);
		}
	/* crossing sides (i, i+1) and (j, j+1)
	   crossing corner i is treated as side (i, i+1)
	   returned in the same order as the line hits the convex */
	return res;
} // convex cut: (r, l]
