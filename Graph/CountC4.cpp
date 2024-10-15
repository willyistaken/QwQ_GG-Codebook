namespace C4 {
    const int N = 1e5 + 5; // change
    vector<int> eg[N], to[N];
    int pl[N], ln, pd[N], id[N], cnt[N];
    ll ans;
    inline void addedge(int x, int y) {
        eg[x].pb(y), eg[y].pb(x);
    }
    ll blt(int n) {
        priority_queue<pii> pq;
        for (int i = 1; i <= n; i++)
            pq.push(pii(pd[i] = -size(eg[i]), i));
        while (!pq.empty()) {
            pii tp = pq.top();
            pq.pop();
            if (id[tp.second])
                continue;
            pl[++ln] = tp.second;
            id[tp.second] = ln;
            for (int v : eg[tp.second])
                if (!id[v])
                    to[v].pb(tp.second), pq.push(pii(++pd[v], v));
        }
        ans = 0;
        for (int p = 1; p <= n; p++) {
            for (int u : to[pl[p]])
                for (int v : eg[u])
                    if (id[v] < p)
                        ans += cnt[v]++;
            for (int u : to[pl[p]])
                for (int v : eg[u])
                    cnt[v] = 0;
        }
        return ans;
    }
}
