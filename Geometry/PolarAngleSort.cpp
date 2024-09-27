struct PolarCMP {
    static P base(0, 0);
    inline bool updown(const P &a) {
        if (fabs(a.y) < eps)
            return a.x > eps;
        return a.y > eps;
    }
    bool cmp(const P &a, const P &b) {
        bool ba = updown(a), bb = updown(b);
        if (ba ^ bb)
            return ba;
        return ori(bs, a, b) > 0;
    }
};