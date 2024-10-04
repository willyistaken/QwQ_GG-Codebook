struct BellmonFord {
    struct E {
        int u, v;
        ll w;
        int s() { return u < v ? u : -u; }
    };
    int n;
    ll inf = LONG_LONG_MAX;
    vector<ll> d;
    vector<E> e;
    BellmonFord(int _n) : n(_n), e(0) {}
    void add_edge(int u, int v, ll w) { e.pb(E{u, v, w}); }
    void go(int s) {
        d.assign(n, inf);
        vector<int> p(n, -1);
        d[s] = 0;
        sort(iter(e), [](E a, E b) { return a.s() < b.s(); });
        int lim = n / 2 + 2;
        for (int i = 0; i < lim; ++i)
            for (auto [u, v, w] : e) {
                if (abs(d[u]) == inf)
                    continue;
                if (d[v] > d[u] + w) {
                    p[v] = u;
                    d[v] = (i < lim - 1 ? d[u] + w : -inf);
                }
            }
        for (int i = 0; i < lim; ++i)
            for (auto [u, v, w] : e)
                if (d[u] == -inf)
                    d[v] = -inf;
    }
};
