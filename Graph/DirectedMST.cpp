struct DirectedMST { // root -> all, O(m lg^2 n)
    struct edge { int u, v; ll w; };
    using T = pair<ll, int>;
    struct PQ : priority_queue<T> {
        ll off = 0;
        void psh(T v) { emplace(off - v.first, v.second); }
        T tp() { return {off - top().first, top().second}; }
        void jn(PQ &b) {
            if (size(*this) < size(b)) std::swap(*this, b);
            while (!b.empty()) psh(b.tp()), b.pop();
        }
    };
    int n;
    vector<edge> e;
    DirectedMST(int _n) : n(_n) {}
    void add_edge(int u, int v, ll w) { e.pb(edge{u, v, w}); }
    vector<int> slv(int root) { // 0-based, edge idx, no sol iff wrong size
        vector<PQ> h(n * 2);
        for (int i = 0; i < size(e); ++i)
            h[e[i].v].psh({e[i].w, i});
        vector<int> a(n * 2), v(n * 2, -1), pa(n * 2, -1), r(n * 2);
        iota(iter(a), 0);
        auto o = [&](int x) { while (a[x] != x) x = a[x] = a[a[x]]; return x; };
        v[root] = n + 1;
        int pc = n;
        for (int i = 0; i < n; ++i)
            if (v[i] == -1)
                for (int p = i; v[p] == -1 || v[p] == i; p = o(e[r[p]].u)) {
                    if (v[p] == i) {
                        int q = p;
                        p = pc++;
                        do {
                            h[q].off = h[q].top().first;
                            h[pa[q] = a[q] = p].jn(h[q]);
                        } while ((q = o(e[r[q]].u)) != p);
                    }
                    v[p] = i;
                    while (!h[p].empty() && o(e[h[p].tp().second].u) == p)
                        h[p].pop();
                    if (h[p].empty())
                        return {};
                    r[p] = h[p].tp().second;
                }
        vector<int> ans;
        for (int i = pc - 1; i >= 0; i--)
            if (i != root && v[i] != n) {
                for (int f = e[r[i]].v; f != -1 && v[f] != n; f = pa[f])
                    v[f] = n;
                ans.pb(r[i]);
            }
        return ans;
    }
};
