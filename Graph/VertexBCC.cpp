struct VertexBCC { // !simple affect BCCofE
	int n, m, dft;
	vector<int> low, dfn, bln, is_ap, st1, st2, BCCofE;
	vector<pii> E;
	vector<vector<pii>> G;
	vector<vector<int>> nG, bcc;
	void dfs(int u, int f) {
		int child = 0;
		low[u] = dfn[u] = ++dft, st1.pb(u);
		for (auto [v, id] : G[u])
			if (!dfn[v]) {
				st2.pb(id);
				dfs(v, u), ++child;
				tmin(low[u], low[v]);
				if (dfn[u] <= low[v]) {
					is_ap[u] = 1, bln[u] = bln[v] = size(bcc);
					bcc.pb(vector<int>(1, u)), bcc.back().pb(v);
					for (; st1.back() != v; st1.pop_back())
						bcc.back().pb(st1.back()), bln[st1.back()] = bln[u];
					st1.pop_back();
					while (st2.back() != id)
						BCCofE[st2.back()] = bln[u], st2.pop_back();
					BCCofE[id] = bln[u], st2.pop_back();
				}
			}
			else if (v != f) {
				tmin(low[u], dfn[v]);
				if (dfn[v] < dfn[u])
					st2.pb(id);
			}
		if (f == -1 && child < 2)
			is_ap[u] = 0;
		if (f == -1 && child == 0)
			bcc.pb(vector<int>(1, u));
	}
	VertexBCC(int _n) : n(_n), m(0), E(0), low(n), dfn(n), bln(n), G(n) {}
	void add_edge(int u, int v) {
		E.pb(u, v), G[u].pb(v, m), G[v].pb(u, m++);
	}
	void slv() {
		is_ap.assign(n, 0), dfn = is_ap;
		dft = 0, st1.clear(), st2.clear();
		BCCofE.assign(m, -1);
		for (int i = 0; i < n; ++i)
			if (!dfn[i])
				dfs(i, -1);
	}
	void block_cut_tree() {
		int tmp = size(bcc);
		for (int i = 0; i < n; ++i)
			if (is_ap[i])
				bln[i] = tmp++;
		nG.assign(tmp, vector<int>(0));
		for (int i = 0; i < size(bcc); ++i)
			for (int j : bcc[i])
				if (is_ap[j])
					nG[i].pb(bln[j]), nG[bln[j]].pb(i);
	} // up to 2 * n - 2 nodes!! bln[i] for id
};
