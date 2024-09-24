struct DOT {
    static const int N = 2e5 + 5; // change
    int dfn[N], id[N], dfc, fa[N], idm[N], sdm[N], bst[N];
    vector<int> G[N], rG[N];
    void ini(int n) {
        for (int i = 1; i <= n; i++)
            G[i].clear(), rG[i].clear();
        fill(dfn, dfn + n + 1, 0);
    }
    inline void adeg(int u, int v) { G[u].pb(v), rG[v].pb(u); }
    int f(int x, int lm) {
        if (x <= lm)
            return x;
        int cr = f(fa[x], lm);
        if (sdm[bst[fa[x]]] < sdm[bst[x]])
            bst[x] = bst[fa[x]];
        return fa[x] = cr;
    }
    void dfs(int u) {
        id[dfn[u] = ++dfc] = u;
        for (int v : G[u])
            if (!dfn[v])
                dfs(v), fa[dfn[v]] = dfn[u];
    }
    void tar(vector<int> *eg, int rt) {
        dfc = 0, dfs(rt);
        for (int i = 1; i <= dfc; i++)
            sdm[i] = bst[i] = i;
        for (int i = dfc; i > 1; i--) {
            int u = id[i];
            for (int v : rG[u])
                if ((v = dfn[v]))
                    f(v, i), tmin(sdm[i], sdm[bst[v]]);
            eg[sdm[i]].pb(i), u = fa[i];
            for (int v : eg[u])
                f(v, u), idm[v] = (sdm[bst[v]] == u ? u : bst[v]);
            eg[u].clear();
        }
        for (int i = 2; i <= dfc; i++) {
            if (sdm[i] != idm[i])
                idm[i] = idm[idm[i]];
            eg[id[idm[i]]].pb(id[i]);
        }
    }
};