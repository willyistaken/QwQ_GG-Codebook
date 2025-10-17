// b = a^{-1}
bool Inverse(vector<vector<int>> &a, vector<vector<int>> &b) {
	int h = size(a);
	for (auto &i : a)
		assert(h == size(i));
	for (int i = 0; i < h; ++i) {
		a[i].resize(2 * h);
		a[i][i + h] = 1;
	}
	GaussElim(a, h);
	for (int i = 0; i < h; ++i)
		if (!a[i][i])
			return 0; // no sol
	b.resize(h);
	for (int i = 0; i < h; ++i) {
		b[i] = vector<int>(a[i].begin() + h, a[i].end());
		int coeff = minv(a[i][i]);
		for (auto &j : b[i])
			j = mmul(j, coeff);
	}
	return 1;
}

