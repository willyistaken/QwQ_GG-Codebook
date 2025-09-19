template <typename T>
inline void FWT(vector<T> &a, int n, int d, int cop, bool inv) {
    d = 1 << d; // cop: 1.AND  2.OR  3.XOR
    for (int i = 0; i < 1 << n; i++) {
        if ((cop == 1 && (~i & d)) || (cop == 2 && (i & d))) {
            if (!inv)
                a[i] += a[i ^ d];
            else
                a[i] -= a[i ^ d];
        } else if (cop == 3 && (~i & d)) {
            tie(a[i], a[i ^ d]) = pair<T, T>(a[i] + a[i ^ d], a[i] - a[i ^ d]);
            if (inv)
                a[i] /= 2, a[i ^ d] /= 2;
        }
    }
}

/*
[A_0  AND:[1 +-1  OR:[1 0 ]  XOR:0.5/1[1  1
 A_1]      0  1]     [+-1 1]          [1 -1]
*/

template <typename T>
vector<T> CONV(vector<T> ar, vector<T> br, int cop) {
    int n = 0;
    while (1 << n < max(size(ar), size(br)))
        n++;
    ar.resize(1 << n), br.resize(1 << n);
    for (int d = 0; d < n; d++)
        FWT(ar, n, d, cop, 0), FWT(br, n, d, cop, 0);
    for (int i = 0; i < 1 << n; i++)
        ar[i] *= br[i];
    for (int d = n - 1; d >= 0; d--)
        FWT(ar, n, d, cop, 1);
    return ar;
}

