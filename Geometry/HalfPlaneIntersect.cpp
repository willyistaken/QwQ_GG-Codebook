struct Line{ P X,Y; };
pair<ll,ll> area_pair(Line a, Line b) 
{ return pair<ll,ll>((a.Y - a.X)^(b.X - a.X), (a.Y - a.X)^(b.Y - a.X)); }
bool isin(Line l0, Line l1, Line l2) {
  // Check inter(l1, l2) strictly in l0
  auto [a02X, a02Y] = area_pair(l0, l2);
  auto [a12X, a12Y] = area_pair(l1, l2);
  if (a12X - a12Y < 0) a12X *= -1, a12Y *= -1;
  return (__int128) a02Y * a12X - (__int128) a02X * a12Y > 0; // C^4
}
/* Having solution, check size > 2 */
/* --^-- Line.X --^-- Line.Y --^-- */
/* add polar angle sort below:*/
/* add polar angle sort above:*/
vector<Line> halfPlaneInter(vector<Line> arr) {
  sort(iter(arr), [&](Line a, Line b) -> int {
    return cmp(a.Y - a.X, b.Y - b.X);
  });
  deque<Line> dq(1, arr[0]);
  for (auto p : arr) {
    if (((dq.back().Y - dq.back().X) ^ (p.Y - p.X)) == 0)
      continue;
    while (size(dq) >= 2 && !isin(p, dq[size(dq) - 2], dq.back()))
      dq.pop_back();
    while (size(dq) >= 2 && !isin(p, dq[0], dq[1]))
      dq.pop_front();
    dq.pb(p);
  }
  while (size(dq) >= 3 && !isin(dq[0], dq[size(dq) - 2], dq.back()))
    dq.pop_back();
  while (size(dq) >= 3 && !isin(dq.back(), dq[0], dq[1]))
    dq.pop_front();
  return vector<Line>(iter(dq));
}

