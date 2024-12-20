template <unsigned P>
struct mint { // P not prime break /=
    unsigned v;
     mint(ll v = 0) : v((v%P+P) % P) {}
     mint &operator+=(mint const &o) {
        v = (v += o.v) >= P ? v - P : v;
        return *this;
    }
     mint &operator-=(mint const &o) {
        v = (v < o.v) ? v + P - o.v : v - o.v;
        return *this;
    }
     mint &operator*=(mint const &o) {
        v = 1ll * v * o.v % P;
        return *this;
    }
     friend mint operator+(mint const &a, mint const &b) {
        return mint(a) += b;
    }
     friend mint operator-(mint const &a, mint const &b) {
        return mint(a) -= b;
    }
     friend mint operator*(mint const &a, mint const &b) {
        return mint(a) *= b;
    }
     inline mint pow(ll n) const {
        mint r(1);
        mint a = v;
        for (; n; a *= a, n >>= 1)
            r *= (n & 1) ? (a) : (mint(1));
        return r;
    }
     mint &operator/=(mint const &o) {
        *this *= o.pow(P - 2);
        return *this;
    }
     friend mint operator/(mint const &a, mint const &b) {
        return mint(a) /= b;
    }
     friend ostream &operator<<(ostream &os, mint const &m) {
        return os << m.v;
    }
     friend istream &operator>>(istream &is, mint &m) {
        return is >> m.v;
    }
};
