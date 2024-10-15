typedef complex<double> cd;
struct FFT {
    // #define M_PI 3.14159265358979323846264338327950288
    static const int K = 19, N = 1 << K; // change
    cd pl[N];
    int rv[N];
    void fft(vector<cd> &ar) {
        static int n, k;
        n = size(ar), k = log2(n);
        if (n <= 1)
            return;
        for (int i = 1; i < n; i++)
            if (i < rv[i] >> (K - k))
                swap(ar[i], ar[rv[i] >> (K - k)]);
        cd a, b;
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
    void pmul(vector<cd> &a, vector<cd> &b, vector<cd> &c) {
        static int pla, plb, n;
        pla = size(a), plb = size(b), n = pla + plb - 1;
        while (n & (n - 1))
            n += lowbit(n);
        a.resize(n), b.resize(n);
        fft(a), fft(b);
        c.resize(n);
        for (int i = 0; i < n; i++)
            c[-i & (n - 1)] = a[i] * b[i] / (double)n;
        fft(c), c.resize(pla + plb - 1);
        a.resize(pla), b.resize(plb);
    }
    FFT() {
        pl[1] = polar(1.0, 0.0);
        for (int k = 2; k < N; k <<= 1)
            for (int i = k; i < k << 1; i++)
                pl[i] = polar(1.0, 2.0 * M_PI * (i - k) / (k * 2.0));
        for (int i = 1, hb = -1; i < N; i++) {
            if (!(i & (i - 1)))
                hb++;
            rv[i] = rv[i ^ (1 << hb)] | 1 << (K - 1 - hb);
        }
    }
};