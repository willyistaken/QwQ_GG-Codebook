struct SPFA {
    int n;
    vector<ll> d;
    vector<vector<pair<int, ll>>> adj;
    SPFA(int _n) : n(_n), adj(_n, vector<pair<int, ll>>(0)) {}
    void add_edge(int u, int v, ll w) { adj[u].pb(v, w); }
    bool go(int s) {
        vector<int> cnt(n, 0), inq(n, 0);
        queue<int> q;
        d.assign(n, LONG_LONG_MAX);
        d[s] = 0, inq[s] = 1, q.emplace(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop(), inq[u] = 0;
            for (auto [v, w] : adj[u]) {
                if (d[v] > d[u] + w) {
                    if (++cnt[v] >= n)
                        return 0; // negative cycle
                    d[v] = d[u] + w;
                    if (!inq[v])
                        q.emplace(v), inq[v] = 1;
                }
            }
        }
        return 1;
    }
};
