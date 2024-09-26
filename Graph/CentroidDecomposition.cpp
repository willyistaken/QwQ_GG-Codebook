struct CentroidDecomposition {
    vector<vector<int> > g;
    vector<int> sub;
    vector<bool> v;
    vector<vector<int>> tree;
    int root;
    void add_edge(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }
    CentroidDecomposition(const vector<vector<int> > &g_, int isbuild = true) : g(g_) {
        sub.resize(size(g), 0);
        v.resize(size(g), false);
        if (isbuild) build();
    }

    void build() {
        tree.resize(size(g));
        root = build_dfs(0);
    }

    int get_size(int cur, int par) {
        sub[cur] = 1;
        for (auto &dst : g[cur]) {
            if (dst == par || v[dst]) continue;
            sub[cur] += get_size(dst, cur);
        }
        return sub[cur];
    }

    int get_centroid(int cur, int par, int mid) {
        for (auto &dst : g[cur]) {
            if (dst == par || v[dst]) continue;
            if (sub[dst] > mid) return get_centroid(dst, cur, mid);
        }
        return cur;
    }

    int build_dfs(int cur) {
        int centroid = get_centroid(cur, -1, get_size(cur, -1) / 2);
        v[centroid] = true;
        for (auto &dst : g[centroid]) {
            if (!v[dst]) {
                int nxt = build_dfs(dst);
                if (centroid != nxt) tree[centroid].emplace_back(nxt);
            }
        }
        v[centroid] = false;
        return centroid;
    }
};
