void CDQ(int l, int r) {//三維偏序
  if (l == r) return;
  int mid = (l + r) / 2;
  CDQ(l, mid);
  CDQ(mid + 1, r);
  sort(arr + l, arr + mid + 1, cmpB);
  sort(arr + mid + 1, arr + r + 1, cmpB);
  int i = l;
  int j = mid + 1;
  while (j <= r) {
    while (i <= mid && ue[i].b <= ue[j].b) {
      BIT.Add(arr[i].c, arr[i].cnt);
      i++;
    }
    ue[j].res += BIT.Ask(arr[j].c);
    j++;
  }
  for (int k = l; k < i; k++) BIT.Add(arr[k].c, -arr[k].cnt);
  return;
}
