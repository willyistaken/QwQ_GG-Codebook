struct EulerianPath {
	int n, m;
	vector<vector<pii>> adj;
	vector<int> cur, vst;
	vector<pii> ans;
	EulerianPath(int _n) : n(_n), m(0), adj(n, vector<pii>(0)) {}
	void add_edge(int a, int b) { adj[a].pb(b, m++); }
	void dfs(int u) {
		for (; cur[u] < size(adj[u]); ++cur[u]) {
			auto [v, id] = adj[u][cur[u]];
			if (vst[id]) continue;	
			vst[id] = 1, dfs(v);
			ans.pb(u, v);
		}
	}
	bool go() {
		vector<int> in(n, 0), out(n, 0);
		for (int i = 0; i < n; ++i) {
			out[i] = size(adj[i]);
			for (auto [j, id] : adj[i])
				++in[j];
		}
		int s = -1, t = -1, ss = -1;
		for (int i = 0; i < n; ++i) {
			if (out[i]) ss = i;
			if (in[i] == out[i]) continue;
			if (in[i] + 1 == out[i]) {
				if (s != -1) return 0;
				s = i;
				continue;
			}
			if (in[i] - 1 == out[i]) {
				if (t != -1) return 0;
				t = i;
				continue;
			}
			return 0;
		}
		if (s == -1) s = ss;
		cur.assign(n, 0), vst.assign(m, 0), ans.clear();
		dfs(s), reverse(iter(ans));
		return accumulate(iter(vst), 0) == m;
	}
};
