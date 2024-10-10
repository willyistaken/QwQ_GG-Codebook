bool in(const P &a, const vector<P> &hl) {
    int ln = size(hl);
    if (ln == 1)
        return a == hl[0];
    if (ln == 2) {
        return !ori(hl[0], hl[1], a) && within(a, hl[0], hl[1]);
    }
    int l = 1, r = ln - 1, m;
    while (l < r - 1) {
        m = (l + r) >> 1;
        if (ori(hl[0], a, hl[m]) < 0)
            l = m;
        else
            r = m;
    }
    return ori(hl[0], hl[l], a) >= 0 && ori(hl[l], hl[r], a) >= 0 && ori(hl[r], hl[0], a) >= 0;
}