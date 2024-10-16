struct TwoSAT { // SCC needed
	int n;
	vector<bool> istrue;
	SCC scc;
	TwoSAT(int _n) : n(_n), scc(n + n) { }
	int rv(int a) { return a >= n ? a - n : a + n; }
	void add_clause(int a, int b) {
		scc.add_edge(rv(a), b);
		scc.add_edge(rv(b), a);
	}
	bool slv() {
		scc.slv(), istrue.assign(n + n, 0);
		for (int i = 0; i < n; ++i) {
			if (scc.bln[i] == scc.bln[i + n]) return 0;
			istrue[i] = scc.bln[i] < scc.bln[i + n];
			istrue[i + n] = !istrue[i];
		}
		return 1;
	}
};
