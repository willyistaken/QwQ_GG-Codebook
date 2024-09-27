typedef complex<double> cd;
struct FFT {
    // #define M_PI 3.14159265358979323846264338327950288
    static const int K = 21, N = 1 << K; // change
    cd pl[N];
    int rv[N];
    void fft(vector<cd> &ar) {
        int n = size(ar), k = log2(n);
        if (n <= 1)
            return;
        for (int i = 1; i < n; i++)
            if (i < rv[i] >> (K - k))
                swap(ar[i], ar[rv[i] >> (K - k)]);
        cd a, b;
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
    void pmul(vector<cd> &a, vector<cd> &b, vector<cd> &c) {
        int n = size(a) + size(b) - 1;
        int pn = n;
        while (n & (n - 1))
            n += lowbit(n);
        a.resize(n), b.resize(n);
        fft(a), fft(b);
        c.resize(n);
        for (int i = 0; i < n; i++)
            c[-i & (n - 1)] = a[i] * b[i] / (double)n;
        fft(c), c.resize(pn);
    }
    FFT() {
        for (int i = 0; i < N; i++)
            pl[i] = polar(1.0, 2 * M_PI * i / N);
        for (int i = 1, hb = -1; i < N; i++) {
            if (!(i & (i - 1)))
                hb++;
            rv[i] = rv[i ^ (1 << hb)] | 1 << (K - 1 - hb);
        }
    }
};