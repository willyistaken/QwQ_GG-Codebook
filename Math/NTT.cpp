struct NTT {
    static const int K = 19, N = 1 << K, M = 998244353; // change
    typedef mint<M> mi;
    mi pl[N];
    int rv[N];
    void ntt(vector<mi> &ar) {
        int n = size(ar), k = log2(n);
        if (n <= 1)
            return;
        for (int i = 1; i < n; i++)
            if (i < rv[i] >> (K - k))
                swap(ar[i], ar[rv[i] >> (K - k)]);
        mi a, b;
        for (int l = 1, p = 1 << (K - 1); l < n; l <<= 1, p >>= 1) {
            for (int i = 0; i < n; i += l << 1) {
                for (int j = 0; j < l; j++) {
                    a = ar[i + j], b = ar[i + j + l];
                    ar[i + j] = a + b * pl[j * p];
                    ar[i + j + l] = a + b * pl[(j + l) * p];
                }
            }
        }
    }
    void pmul(vector<mi> &a, vector<mi> &b, vector<mi> &c) {
        int pla = size(a), plb = size(b), n = pla + plb - 1;
        while (n & (n - 1))
            n += lowbit(n);
        a.resize(n), b.resize(n);
        ntt(a), ntt(b);
        c.resize(n);
        mi ivn(1);
        ivn /= n;
        for (int i = 0; i < n; i++)
            c[-i & (n - 1)] = a[i] * b[i] * ivn;
        ntt(c), c.resize(pla + plb - 1);
        a.resize(pla), b.resize(plb);
    }
    NTT() {
        pl[0] = 1, pl[1] = mi(3).pow((M - 1) / N);
        for (int i = 2; i < N; i++)
            pl[i] = pl[i - 1] * pl[1];
        for (int i = 1, hb = -1; i < N; i++) {
            if (!(i & (i - 1)))
                hb++;
            rv[i] = rv[i ^ (1 << hb)] | 1 << (K - 1 - hb);
        }
    }
};