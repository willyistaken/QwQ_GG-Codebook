struct EdgeBCC {
	int n, m, dft, necc;
	vector<int> low, dfn, bln, is_bridge, stk;
	vector<vector<pii>> G;
	void dfs(int u, int f) {
		dfn[u] = low[u] = ++dft, stk.pb(u);
		for (auto [v, id] : G[u])
			if (!dfn[v])
				dfs(v, id), tmin(low[u], low[v]);
			else if (id != f) 
				tmin(low[u], dfn[v]);
		if (low[u] == dfn[u]) {
			if (f != -1) is_bridge[f] = 1;
			for (; stk.back() != u; stk.pop_back())
				bln[stk.back()] = necc;
			bln[u] = necc++, stk.pop_back();
		}
	}
	EdgeBCC(int _n): n(_n), m(0), low(n), bln(n), G(n) {}
	void add_edge(int u, int v) {
		G[u].pb(v, m), G[v].pb(u, m++);
	}
	void slv() {
		is_bridge.assign(m, 0), stk.clear();
		dfn.assign(n, 0), dft = necc = 0;
		for (int i = 0; i < n; ++i)
			if (!dfn[i]) dfs(i, -1);
	}
}; // ecc_id(i): bln[i]

