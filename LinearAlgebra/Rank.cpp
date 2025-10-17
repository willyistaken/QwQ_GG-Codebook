int Rank(vector<vector<int>> &a) {
	if (a.empty()) return 0;
	GaussElim(a, size(a[0]));
	int r = 0;
	for (int i = 0; i < size(a); ++i)
		for (int &j : a[i])
			if (j) {
				++r;
				break;
			}
	return r;
}

