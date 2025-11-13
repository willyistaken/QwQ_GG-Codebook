// aX = b, X = x + \sum c_i * bs_i
bool LinearSys(vector<vector<int>>& a, const vector<int> &b, vector<int> &x, vector<vector<int>> &bs) {
	int h = size(a), w = size(a[0]);
	assert(h == size(b));
	for (int i = 0; i < h; ++i)
		a[i].pb(b[i]);
	GaussElim(a, w);
	x.assign(w, 0);
	vector<int> tag(w, 0), col(h, -1);
	for (int i = 0; i < h; ++i)
		for (int j = 0; j <= w; ++j)
			if (a[i][j]) {
				if (j == w) return 0; // no sol
				x[j] = mmul(a[i][w], minv(a[i][j]));
				tag[j] = 1, col[i] = j;
				break;
			}
	bs.clear();
	for (int i = 0; i < w; ++i)
		if (!tag[i]) {
			vector<int> vec(w, 0);
			vec[i] = 1;
			for (int j = 0; j < h; ++j)
				if (~col[j])
					vec[col[j]] = madd(mod, -mmul(a[j][i], minv(a[j][col[j]])));
			bs.pb(vec);
		}
	return 1;
}

