struct Fast_Walsh_Transform { // Modint needed
    string op; // and, or, xor
    void fwt(vector<mint> &v, bool ifwt) {
        int n = __lg(size(v));
        mint iv2 = mint(1) / 2;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 1 << n; ++j)
                if (op == "and" && (~j >> i & 1) || op == "or" && (j >> i & 1)) {
                    if (!ifwt)
                        v[j] += v[j ^ (1 << i)];
                    else
                        v[j] -= v[j ^ (1 << i)];
                } else if (op == "xor" && (j >> i & 1)) {
                    mint x = v[j ^ (1 << i)], y = v[j];
                    if (!ifwt)
                        v[j ^ (1 << i)] = x + y, v[j] = x - y;
                    else
                        v[j ^ (1 << i)] = (x + y) * iv2, v[j] = (x - y) * iv2;
                }
    }
    vector<mint> v1, v2; // size(v1) = size(v2) = 2^k
    Fast_Walsh_Transform(const vector<mint> &_v1, const vector<mint> &_v2, const string &_op) : v1(_v1), v2(_v2), op(_op) {}
    vector<mint> solve() { // ans_k = \sum_{i op j = k} a_i * b_j
        fwt(v1, 0), fwt(v2, 0);
        for (int i = 0; i < size(v1); ++i)
            v1[i] *= v2[i];
        fwt(v1, 1);
        return v1;
    }
};
