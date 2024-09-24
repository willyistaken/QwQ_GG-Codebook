struct frac
{
	ll n, d;
	frac(const ll &_n = 0, const ll &_d = 1) : n(_n), d(_d)
	{
		ll t = __gcd(n, d);
		n /= t, d /= t;
		if (d < 0)
			n = -n, d = -d;
	}
	frac operator-() const
	{
		return frac(-n, d);
	}
	frac operator+(const frac &b) const
	{
		return frac(n * b.d + b.n * d, d * b.d);
	}
	frac operator-(const frac &b) const
	{
		return frac(n * b.d - b.n * d, d * b.d);
	}
	frac operator*(const frac &b) const
	{
		return frac(n * b.n, d * b.d);
	}
	frac operator/(const frac &b) const
	{
		return frac(n * b.d, d * b.n);
	}
	void print()
	{
		cout << n;
		if (d != 1)
			cout << "/" << d;
	}
};
