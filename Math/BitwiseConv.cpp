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