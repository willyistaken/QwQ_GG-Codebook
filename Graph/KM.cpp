struct KM {
    static const int N = 505;
    int pr[N], eg[N][N], m1[N], m2[N], n;
    ll lx[N], ly[N], sl[N];
    bool vy[N];
    ll ans;
    inline void ini(int _n) {
        n = _n;
        memset(lx + 1, ~INF, n << 3);
        memset(ly + 1, 0, n << 3);
        memset(m1 + 1, 0, n << 2);
        memset(m2 + 1, 0, n << 2);
        for (int i = 1; i <= n; i++)
            memset(eg[i] + 1, ~INF, n << 2);
    }
    inline void addedge(int u, int v, int w) {
        tmax(eg[u][v], w), tmax(lx[u], (ll)w);
    }
    ll getmatch() {
        ans = 0;
        for (int p = 1, u, v; p <= n; p++) {
            memset(sl + 1, INF, n << 3);
            memset(vy + 1, 0, n);
            for (u = p;; u = m2[v], vy[v] = 1) {
                ll mn = 1ll << 60;
                for (int i = 1; i <= n; i++) {
                    if (vy[i])
                        continue;
                    if (eg[u][i] != ~INF && lx[u] + ly[i] - eg[u][i] < sl[i])
                        sl[i] = lx[u] + ly[i] - eg[u][i], pr[i] = u;
                    if (sl[i] < mn)
                        mn = sl[i], v = i;
                }
                for (int i = 1; i <= n; i++) {
                    if (vy[i])
                        ly[i] += mn, lx[m2[i]] -= mn;
                    else
                        sl[i] -= mn;
                }
                lx[p] -= mn;
                if (!m2[v])
                    break;
            }
            while (v)
                u = pr[v], m2[v] = u, swap(v, m1[u]);
        }
        for (int i = 1; i <= n; i++)
            ans += eg[i][m1[i]];
        return ans;
    }
};
