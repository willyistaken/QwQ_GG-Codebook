struct BCT {
    static const int N = 1e6 + 5; // change
    vector<int> e1[N], e2[N], sk; // e2 is the new tree
    int low[N], dfn[N], ctd = 0, ctn = 0;
    bool vs[N];
    void dfs(int u, int fa) {
        dfn[u] = low[u] = ++ctd;
        sk.pb(u), vs[u] = 1;
        for (int v : e1[u]) {
            if (v == fa)
                continue;
            if (dfn[v]) {
                if (vs[v])
                    tmin(low[u], dfn[v]);
                continue;
            }
            dfs(v, u), tmin(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                e2[u].pb(++ctn);
                int x;
                do {
                    x = sk.back();
                    sk.pop_back();
                    e2[ctn].pb(x);
                } while (x != v);
            }
        }
        vs[u] = 0;
    }
    inline void addedge(int x, int y) { e1[x].pb(y), e1[y].pb(x); }
    inline void ini(int n, int rt) {
        for (int i = 1; i <= ctn; i++)
            e1[i].clear(), e2[i].clear();
        ctn = n, ctd = 0;
        memset(dfn + 1, 0, n << 2);
        memset(vs + 1, 0, n);
        sk.clear();
        dfs(rt, -1);
    }
};
