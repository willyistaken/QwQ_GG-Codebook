struct BIT {
    int n;
    vector<int> a;
    BIT(int _n) : n(_n), a(n + 1, 0) {}
    inline void update(int x, int k) {
        for (; x <= n; x += lowbit(x))
            a[x] += k;
    }
    inline int query(int x) {
        if (x <= 0)
            return 0;
        int ret = 0;
        for (; x; x ^= lowbit(x))
            ret += a[x];
        return ret;
    }
    inline int query(int l, int r) {
        return query(r) - query(l - 1);
    }
    inline int kth(int k) {
        int x = 0;
        for (int i = 1 << __lg(n); i; i >>= 1)
            if (x + i <= n && k > a[x + i])
                x += i, k -= a[x];
        return x + 1;
    }
};
