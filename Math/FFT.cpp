typedef complex<double> cp;
void fft(vector<cp> &f, int rev) {
    const double PI = 3.14159265358979363;
    int n = size(f);
    if (n == 1)
        return;
    vector<cp> o(n / 2), e(n / 2);
    for (int i = 0; i < n; i++) {
        if (i & 1)
            o[i / 2] = (f[i]);
        else
            e[i / 2] = (f[i]);
    }
    fft(o, rev);
    fft(e, rev);
    cp cur(1, 0);
    cp step(cos(2 * PI / n), sin(rev * 2 * PI / n));
    for (int i = 0; i < n / 2; i++) {
        f[i] = e[i] + cur * o[i];
        f[i + n / 2] = e[i] - cur * o[i];
        if (rev < 0) {
            f[i] /= 2;
            f[i + n / 2] /= 2;
        }
        cur *= step;
    }
}
