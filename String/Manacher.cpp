vector<int> manacher(string &s) {//pad s with $->$a$b$c....z$, realans = ans-1.
  string t(size(s) * 2 + 1, '$');
  for(int i=0;i<size(s);i++) t[i * 2 + 1] = s[i];
  int n = size(t), m = 0, r = 0;
  vector<int> p(n);
  for(int i=0;i<n;i++) {
    p[i] = (r > i ? min(r - i, p[m - (i - m)]) : 1);
    while (i-p[i]>=0 && i + p[i] < n &&
        t[i - p[i]] == t[i + p[i]]) ++p[i];
    if (i + p[i] > r) m = i, r = i + p[i];
  }
  return p;
}
