struct MCMF {
    static const int N = 5005, M = N * 20;
    struct E {
        int to, cap, co, nxt;
    } eg[M];
    int dp[N], hd[N], cr[N], ct = 2, s = 0, t = 1, n, flow, cost;
    bool vd[N];
    inline void ini(int _n) { n = _n; }
    inline void addedge(int u, int v, int w, int c) {
        eg[ct] = {v, w, c, hd[u]};
        hd[u] = ct++;
        eg[ct] = {u, 0, -c, hd[v]};
        hd[v] = ct++;
    }
    bool spfa() {
        queue<int> q;
        memset(dp, INF, (n + 1) << 2);
        q.push(s), vd[s] = 1, dp[s] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop(), vd[u] = 0;
            for (int i = hd[u]; i; i = eg[i].nxt) {
                const int v = eg[i].to, c = eg[i].co;
                if (!eg[i].cap || dp[u] + c >= dp[v])
                    continue;
                dp[v] = dp[u] + c;
                if (!vd[v])
                    vd[v] = 1, q.push(v);
            }
        }
        return dp[t] != INF;
    }
    int dfs(int u, int fl) {
        if (u == t)
            return fl;
        int sm = 0;
        vd[u] = 1;
        for (int &i = cr[u]; i; i = eg[i].nxt) {
            int &w = eg[i].cap, v = eg[i].to, c = eg[i].co;
            if (!w || vd[v] || dp[u] + c != dp[v])
                continue;
            int tp = dfs(v, min(fl - sm, w));
            w -= tp, eg[i ^ 1].cap += tp, sm += tp, cost += tp * c;
        }
        vd[u] = 0;
        return sm;
    }
    pii getflow() {
        flow = cost = 0;
        while (spfa())
            memcpy(cr, hd, (n + 1) << 2), flow += dfs(s, INF);
        return pii(flow, cost);
    }
};