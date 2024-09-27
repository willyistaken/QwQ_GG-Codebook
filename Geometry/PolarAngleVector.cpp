P BASE(0, 0), BASEV(1, 0);
inline bool updown(const P &a) {
    int tmp = ori(BASE, BASE + BASEV, a);
    if (!tmp)
        return BASEV * (a - BASE) > 0;
    return tmp > 0;
}
bool cmp(const P &a, const P &b) {
    bool ba = updown(a), bb = updown(b);
    if (ba ^ bb)
        return ba;
    return ori(BASE, a, b) > 0;
}
