void GaussElim(vector<vector<int>> &a, int lim) {
	int h = size(a), w = size(a[0]);
	for (auto &i : a)
		assert(w == size(i));
	assert(lim <= w);
	vector<int> deg(h, 0);
	for (int i = 0; i < h; ++i)
		for (auto &j : a[i])
			deg[i] += j > 0;
	int r = 0;
	for (int c = 0; c < lim; ++c) {
		int id = -1;
		for (int i = r; i < h; ++i)
			if (a[i][c] && (id == -1 || deg[i] < deg[id]))
				id = i;
		if (id == -1) continue;
		if (id > r) {
			swap(a[r], a[id]);
			swap(deg[r], deg[id]);
			for (int j = c; j < w; ++j)
				a[id][j] = madd(mod, -a[id][j]);
		}
		vector<int> nzr;
		for (int j = c; j < w; ++j)
			if (a[r][j]) nzr.pb(j);
		int inva = minv(a[r][c]);
		for (int i = r + 1; i < h; ++i) {
			if (!a[i][c]) continue;
			int coeff = madd(mod, -mmul(a[i][c], inva));
			for (int j : nzr) {
				if (a[i][j]) --deg[i];
				a[i][j] = madd(a[i][j], mmul(coeff, a[r][j]));
				if (a[i][j]) ++deg[i];
			}
		}
		++r;
	}
	for (r = h - 1; r >= 0; --r)
		for (int c = 0; c < lim; ++c)
			if (a[r][c]) {
				int inva = minv(a[r][c]);
				for (int i = r - 1; i >= 0; --i) {
					if (!a[i][c]) continue;
					int coeff = madd(mod, -mmul(a[i][c], inva));
					for (int j = c; j < w; ++j)
						a[i][j] = madd(a[i][j], mmul(coeff, a[r][j]));
				}
				break;
			}
}

