// find x,y such that ax+by=gcd(a,b)
ll exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = exgcd(b, a % b, y, x);
	return y -= a/b * x, d;
}
ll CRT(int k, ll* a, ll* r) {
  ll n = 1, ans = 0;
  for (int i = 1; i <= k; i++) n = n * r[i];
  for (int i = 1; i <= k; i++) {
    ll m = n / r[i], b, y;
    exgcd(m, r[i], b, y);  // b * m mod r[i] = 1
    ans = (ans + a[i] * m * b % n) % n;
  }
  return (ans % n + n) % n;
}
// not coprime: x = m1p+a1 = m2q+a2 => m1p-m2q = a2-a1, use exgcd
