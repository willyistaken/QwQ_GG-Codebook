vector<int> manacher(string &ss){ //biggest k such [i-k+1,i]=[i~i+k-1],padded with $
  string s;
  s.resize(ss.size()*2+1,'$');
  for(int i=0;i<ss.size();i++){
    s[i*2+1]=ss[i];
  }
  vector<int> p(s.size(),1);
  for(int i=0,l=0,r=0;i<s.size();i++){
    p[i]=max(min(p[l*2-i],r-i),1LL);
    while(0<=i-p[i]&&i+p[i]<s.size()&&s[i-p[i]]==s[i+p[i]]){
      l=i,r=i+p[i],p[i]++;
    }
  }
  return p;
}

