inline char gc() {
    const static int SZ = 1 << 16;
    static char buf[SZ], *p1, *p2;
    if (p1 == p2 && (p2 = buf + fread(p1 = buf, 1, SZ, stdin), p1 == p2))
        return -1;
    return *p1++;
}
void rd() {}
template <typename T, typename... U>
void rd(T &x, U &...y) {
    x = 0;
    bool f = 0;
    char c = gc();
    while (!isdigit(c))
        f ^= !(c ^ 45), c = gc();
    while (isdigit(c))
        x = (x << 1) + (x << 3) + (c ^ 48), c = gc();
    f && (x = -x), rd(y...);
}

template <typename T>
void prt(T x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        prt(x / 10);
    putchar((x % 10) ^ 48);
}