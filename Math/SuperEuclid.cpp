//0~(n-1)!!!! sum floor((ax+b)/m)
ll semiEuclid(ll a,ll b,ll m,ll n){
  if(a==0) return (b/m)*(n);
  if(a >= m or b >= m) return n*(n-1)/2*(a/m) + n*(b/m) + semiEuclid(a%m,b%m,m,n);
  ll l = (a*(n-1)+b)/m;
  return l*(n-1) - semiEuclid(m,m-b-1,a,l);
}
