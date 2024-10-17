struct SCC {
	int n, dft, nscc;
	vector<int> low, dfn, bln, instk, stk;
	vector<vector<int>> G;
	void dfs(int u) {
		low[u] = dfn[u] = ++dft;
		instk[u] = 1, stk.pb(u);
		for (int v : G[u])
			if (!dfn[v])
				dfs(v), tmin(low[u], low[v]);
			else if (instk[v] && dfn[v] < dfn[u])
				tmin(low[u], dfn[v]);
		if (low[u] == dfn[u]) {
			for (; stk.back() != u; stk.pop_back())
				bln[stk.back()] = nscc, instk[stk.back()] = 0;
			instk[u] = 0, bln[u] = nscc++, stk.pop_back();
		}
	}
	SCC(int _n): n(_n), low(n), bln(n), G(n) {}
	void add_edge(int u, int v) { G[u].pb(v); }
	void slv() {
		dfn.assign(n, 0), instk = dfn, dft = nscc = 0;
		for (int i = 0; i < n; ++i)
			if (!dfn[i]) dfs(i);
	}
}; // scc_id(i): bln[i]

