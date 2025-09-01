template <typename T>
inline void tozero(vector<T> &a, int n, int d) {
    d = 1 << d;
    for (int i = 0; i < 1 << n; i += d << 1) {
        for (int j = 0; j < d; j++) {
            a[i + j] += a[i + j + d];
            a[i + j + d] = 0;
        }
    }
}
template <typename T>
inline void flip(vector<T> &a, int n, int d) {
    d = 1 << d;
    for (int i = 0; i < 1 << n; i += d << 1) {
        for (int j = 0; j < d; j++) {
            swap(a[i + j], a[i + j + d]);
        }
    }
}

template <typename T>
vector<T> GCONV(vector<T> ar, vector<T> br, vector<string> ops) {
    int n = size(ops);
    ar.resize(1 << n), br.resize(1 << n);
    vector<int> op(n, 0);
    int fg = 0;
    for (int d = 0; d < n; d++) {
        if (ops[d][0] == '1') {
            fg ^= (1 << d);
            for (int i = 0; i < 4; i++)
                ops[d][i] = '0' + '1' - ops[d][i];
        }
        if (ops[d] == "0000")
            tozero(ar, n, d), tozero(br, n, d), op[d] = 0;
        else if (ops[d] == "0001")
            op[d] = 1;
        else if (ops[d] == "0010")
            flip(br, n, d), op[d] = 1;
        else if (ops[d] == "0011")
            tozero(br, n, d), op[d] = 2;
        else if (ops[d] == "0100")
            flip(ar, n, d), op[d] = 1;
        else if (ops[d] == "0101")
            tozero(ar, n, d), op[d] = 2;
        else if (ops[d] == "0110")
            op[d] = 3;
        else
            op[d] = 2;
        FWT(ar, n, d, op[d], 0), FWT(br, n, d, op[d], 0);
    }
    for (int i = 0; i < 1 << n; i++)
        ar[i] *= br[i];
    for (int d = n - 1; d >= 0; d--)
        FWT(ar, n, d, op[d], 1);
    for (int i = 0; i < 1 << n; i++)
        if (i < (i ^ fg))
            swap(ar[i], ar[i ^ fg]);
    return ar;
}