void fdhl(vector<P> &ar, vector<P> &hl) {
    sort(iter(ar));
    for (int i = 0; i < 2; i++) {
        int prln = size(hl);
        for (int j = 0; j < size(ar); j++) {
            while (size(hl) - prln > 1 && ori(hl[size(hl) - 1], hl[size(hl) - 2], ar[j]) >= 0)
                hl.pop_back();
            hl.push_back(ar[j]);
        }
        if (size(hl) > 1)
            hl.pop_back();
        reverse(ar.begin(), ar.end());
    }
    if (size(hl) > 1 && hl.front() == hl.back())
        hl.pop_back();
}