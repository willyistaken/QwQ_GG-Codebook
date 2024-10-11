template <unsigned P>
struct mint { // P not prime break /=
    unsigned v;
    constexpr mint(ll v = 0) : v(v % P) {}
    constexpr mint &operator+=(mint const &o) {
        v = (v += o.v) >= P ? v - P : v;
        return *this;
    }
    constexpr mint &operator-=(mint const &o) {
        v = (v < o.v) ? v + P - o.v : v - o.v;
        return *this;
    }
    constexpr mint &operator*=(mint const &o) {
        v = 1ll * v * o.v % P;
        return *this;
    }
    constexpr friend mint operator+(mint const &a, mint const &b) {
        return mint(a) += b;
    }
    constexpr friend mint operator-(mint const &a, mint const &b) {
        return mint(a) -= b;
    }
    constexpr friend mint operator*(mint const &a, mint const &b) {
        return mint(a) *= b;
    }
    constexpr inline mint pow(ll n) const {
        mint r(1);
        mint a = v;
        for (; n; a *= a, n >>= 1)
            r *= (n & 1) ? (a) : (mint(1));
        return r;
    }
    constexpr mint &operator/=(mint const &o) {
        *this *= o.pow(P - 2);
        return *this;
    }
    constexpr friend mint operator/(mint const &a, mint const &b) {
        return mint(a) /= b;
    }
    constexpr friend ostream &operator<<(ostream &os, mint const &m) {
        return os << m.v;
    }
    constexpr friend istream &operator>>(istream &is, mint &m) {
        return is >> m.v;
    }
};