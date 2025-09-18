P BASE(0, 0);
inline bool updown(const P &a) {
    if (fabs(a.y) < eps)
        return a.x > eps;
    return a.y > eps;
}
bool cmp(const P &a, const P &b) {
    bool ba = updown(a - BASE), bb = updown(b - BASE);
    if (ba ^ bb)
        return ba;
    return ori(BASE, a, b) > 0;
}
