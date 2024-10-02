struct BIT {
    int n;
    vector<int> a;
    BIT(int _n) : n(_n), a(n + 1, 0) {}
    void update(int x, int k) {
        for (; x <= n; x += x & -x)
            a[x] += k;
    }
    int query(int x) {
        int ret = 0;
        for (; x; x -= x & -x)
            ret += a[x];
        return ret;
    }
    int kth(int k) {
        int x = 0;
        for (int i = 1 << __lg(n); i; i /= 2)
            if (x + i <= n && k > a[x + i])
                x += i, k -= a[x];
        return x + 1;
    }
};
