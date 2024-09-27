struct P {
#define eps 1e-9
    double x, y;
    P() { x = y = 0; }
    P(double x, double y) : x(x), y(y) {}
    friend bool operator<(const P &a, const P &b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
    friend bool operator==(const P &a, const P &b) { return a.x == b.x && a.y == b.y; }
    friend bool operator!=(const P &a, const P &b) { return a.x != b.x || a.y != b.y; }
    P operator+(const P &b) const { return P(x + b.x, y + b.y); }
    void operator+=(const P &b) { x += b.x, y += b.y; }
    P operator-(const P &b) const { return P(x - b.x, y - b.y); }
    void operator-=(const P &b) { x -= b.x, y -= b.y; }
    P operator*(double b) const { return P(x * b, y * b); }
    void operator*=(double b) { x *= b, y *= b; }
    P operator/(double b) const { return P(x / b, y / b); }
    void operator/=(double b) { x /= b, y /= b; }
    double operator*(const P &b) const { return x * b.x + y * b.y; }
    double operator^(const P &b) const { return x * b.y - y * b.x; }
    double lth() const { return sqrt(x * x + y * y); }
    friend ostream &operator<<(ostream &os, const P &a) {
        return os << '(' << a.x << ' ' << a.y << ')';
    }
};