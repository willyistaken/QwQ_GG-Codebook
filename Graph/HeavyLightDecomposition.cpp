namespace HLD {
    int in[N], ou[N], dfc, top[N], sz[N], fa[N], ch[N];
    vector<int> eg[N];
    inline void addedge(int u, int v) {
        eg[u].pb(v), eg[v].pb(u);
    }
    inline void ini(int n) { // after using
        for (int i = 1; i <= n; i++)
            eg[i].clear();
        memset(ch + 1, 0, n << 2), dfc = 0;
    }
    void dsz(int u) {
        sz[u] = 1;
        for (int v : eg[u]) {
            if (v == fa[u])
                continue;
            fa[v] = u, dsz(v), sz[u] += sz[v];
            if (sz[v] > sz[ch[u]])
                ch[u] = v;
        }
    }
    void dfs(int u) {
        in[u] = ++dfc;
        if (ch[u])
            top[ch[u]] = top[u], dfs(ch[u]);
        for (int v : eg[u])
            if (v != fa[u] && v != ch[u])
                top[v] = v, dfs(v);
        ou[u] = dfc;
    }
    inline void blt(int rt) {
        fa[rt] = 0, dsz(rt), top[rt] = rt, dfs(rt);
    }
    void slv(int u, int v) {
        while (top[u] != top[v]) {
            if (in[top[u]] < in[top[v]])
                swap(u, v);
            // [ in[top[u]], in[u] ];
            u = fa[top[u]];
        }
        if (in[u] > in[v])
            swap(u, v);
        // [ in[u], in[v] ];
    }
}
