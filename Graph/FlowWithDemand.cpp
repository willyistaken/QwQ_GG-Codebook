struct DMFLOW {
    struct FLOW {
        static const int N = 305, M = N * N * 12; // change
        int dp[N], cr[N], hd[N], ct = 2, s = 0, t = 1, n, flow;
        inline void ini(int _n) { n = _n; }
        struct E {
            int to, cap, nxt;
        } eg[M];
        inline void addedge(int u, int v, int w) {
            eg[ct] = {v, w, hd[u]};
            hd[u] = ct++;
            eg[ct] = {u, 0, hd[v]};
            hd[v] = ct++;
        }
        bool bfs() {
            memset(dp, INF, (n + 1) << 2);
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
            flow = 0;
            while (bfs())
                memcpy(cr, hd, (n + 1) << 2), flow += dfs(s, INF);
            return flow;
        }
    } fw;
    int n, sum, s, t;
    inline void ini(int _n) { n = _n, fw.ini(fw.t = n + 1), sum = fw.s = 0; }
    inline void addlr(int u, int v, int l, int r) {
        if (l) {
            fw.addedge(u, fw.t, l);
            fw.addedge(fw.s, v, l);
            sum += l;
        }
        if (r - l)
            fw.addedge(u, v, r - l);
    }
    int slv() {
        fw.addedge(t, s, INF);
        int res = fw.getflow();
        if (res != sum)
            return -1;
        fw.s = s, fw.t = t;
        res = fw.getflow();
        // maximum
        // fw.s = t, fw.t = s;
        // res = INF - fw.getflow();
        // minimum
        return sum = res;
    }
} dmfw;