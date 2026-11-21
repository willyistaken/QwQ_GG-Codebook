// circuit iff ans[0] == ans.back()
struct EulerTrail {	// dir = 0 for undirected
	int n, m, dir;
	vector<vector<pii>> G;
	vector<int> d, cur, vst, ans;
	EulerTrail(int _n, int _dir = 1) : n(_n), m(0), dir(_dir), G(n), d(n, 0) {}
	void add_edge(int a, int b) {
		G[a].pb(b, m);
		if (dir) ++d[a], --d[b];
		else G[b].pb(a, m);
		++m;
	}
	void dfs(int u) {
		for (; cur[u] < size(G[u]); ++cur[u]) {
			auto [v, id] = G[u][cur[u]];
			if (!vst[id]) vst[id] = 1, dfs(v);
		}
		ans.pb(u);
	}
	bool go() {
		if (!m) return 1;	// no edge
		int s = -1, ss = -1, cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (size(G[i])) ss = i;
			int x = dir ? d[i] : size(G[i]) & 1;
			if (!x) continue;
			if (++cnt > 2 || abs(x) > 1) return 0;
			if (x > 0 && s == -1) s = i;
		}
		if (s == -1) s = ss;
		cur.assign(n, 0), vst.assign(m, 0), ans.clear();
		dfs(s), reverse(iter(ans));
		return size(ans) == m + 1;
	}
};
