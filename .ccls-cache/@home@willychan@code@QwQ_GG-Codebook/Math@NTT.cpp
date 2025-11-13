const int M = 998244353;
typedef mint<M> mi;
struct NTT {
    static const int K = 20, N = 1 << K;
    mi pl[N];
    int rv[N];
    void dft(vector<mi> &ar) {
        static int n, k;
        n = size(ar), k = log2(n);
        if (n <= 1)
            return;
        for (int i = 1; i < n; i++)
            if (i < rv[i] >> (K - k))
                swap(ar[i], ar[rv[i] >> (K - k)]);
        static mi a, b;
        for (int l = 1; l < n; l <<= 1) {
            for (int i = 0; i < n; i += l << 1) {
                for (int j = 0; j < l; j++) {
                    a = ar[i + j], b = ar[i + j + l] * pl[j + l];
                    ar[i + j] = a + b;
                    ar[i + j + l] = a - b;
                }
            }
        }
    }
    void idft(vector<mi> &ar) {
        static mi ivn;
        ivn.v = 1, ivn /= size(ar);
        reverse(ar.begin() + 1, ar.end());
        for (mi &i : ar)
            i *= ivn;
        dft(ar);
    }
	template<typename T>
    T pmul(T a, T b) {
        static int n;
        n = size(a) + size(b) - 1;
        while (n & (n - 1))
            n += lowbit(n);
        a.resize(n), b.resize(n);
        dft(a), dft(b);
        for (int i = 0; i < n; i++)
            a[i] *= b[i];
        idft(a), a.resize(n);
        return a;
    }
    NTT() {
        pl[1] = 1;
        for (int k = 1; k < K; k++) {
            mi omega = mi(3).pow((M - 1) >> (k + 1));
            for (int i = 1 << (k - 1); i < 1 << k; i++)
                pl[i * 2] = pl[i], pl[i * 2 + 1] = pl[i] * omega;
        }
        for (int i = 1, hb = -1; i < N; i++) {
            if (!(i & (i - 1)))
                hb++;
            rv[i] = rv[i ^ (1 << hb)] | 1 << (K - 1 - hb);
        }
    }
};
