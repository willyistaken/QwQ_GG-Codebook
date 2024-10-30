struct HK {
    static const int N = 1e5 + 5, M = N * 2; // change, 1-base
    int fr[N], pr[N], hd[N], m1[N], m2[N], to[M], nxt[M], ct = 1, n1, n2, ans;
    inline void ini(int _n1, int _n2) {
        n1 = _n1, n2 = _n2, ct = 1;
        memset(m1 + 1, 0, n1 << 2);
        memset(m2 + 1, 0, n2 << 2);
        memset(hd + 1, 0, n1 << 2);
    }
    inline void addedge(int u, int v) {
        to[ct] = v, nxt[ct] = hd[u], hd[u] = ct++;
    }
    int getmatch() {
        ans = 0;
        for (bool ok = 1; ok;) {
            ok = 0, memset(fr + 1, 0, n1 << 2);
            queue<int> q;
            for (int i = 1; i <= n1; i++)
                if (!m1[i])
                    q.push(fr[i] = i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (m1[fr[u]])
                    continue;
                for (int i = hd[u]; i; i = nxt[i]) {
                    int v = to[i];
                    if (!m2[v]) {
                        while (v)
                            m2[v] = u, swap(m1[u], v), u = pr[u];
                        ok = 1, ans++;
                        break;
                    } else if (!fr[m2[v]])
                        q.push(v = m2[v]), fr[v] = fr[u], pr[v] = u;
                }
            }
        }
        return ans;
    }
};