struct FLOW {
    static const int N = 1e3 + 5, M = N * 10, s = 0, t = 1; // change
    int dp[N], cr[N], hd[N], ct = 2;
    struct E {
        int to, cap, nxt;
    } eg[M];
    inline void adeg(int u, int v, int w) {
        eg[ct] = {v, w, hd[u]};
        hd[u] = ct++;
        eg[ct] = {u, 0, hd[v]};
        hd[v] = ct++;
    }
    bool bfs() {
        memset(dp + 1, INF, ct << 2);
        queue<int> q;
        q.push(s), dp[s] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = hd[u]; i; i = eg[i].nxt) {
                const int v = eg[i].to;
                if (!eg[i].cap || dp[u] + 1 >= dp[v])
                    continue;
                dp[v] = dp[u] + 1, q.push(v);
            }
        }
        return dp[t] != INF;
    }

    int dfs(int u, int fl) {
        if (u == t)
            return fl;
        int sm = 0;
        for (int &i = cr[u]; i; i = eg[i].nxt) {
            int v = eg[i].to, &w = eg[i].cap;
            if (!w || dp[u] + 1 != dp[v])
                continue;
            int tp = dfs(v, min(w, fl - sm));
            w -= tp, sm += tp, eg[i ^ 1].cap += tp;
            if (sm == fl)
                return fl;
        }
        return sm;
    }
    int getflow() {
        int ans = 0;
        while (bfs())
            memcpy(cr + 1, hd + 1, ct << 2), ans += dfs(s, INF);
        return ans;
    }
};