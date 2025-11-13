int Determinant(vector<vector<int>> &a) {
	assert(size(a) == size(a[0]));
	GaussElim(a, size(a));
	int d = 1;
	for (int i = 0; i < size(a); ++i)
		d = mmul(d, a[i][i]);
	return d;
}

