vector<int> manacher(string &ss){ //biggest k such [i-k+1,i]=[i~i+k-1],padded with $
  string s;
  s.resize(size(ss)*2+1,'$');
  for(int i=0;i<size(ss);i++){
    s[i*2+1]=ss[i];
  }
  vector<int> p(size(s),1);
  for(int i=0,l=0,r=0;i<size(s);i++){
    p[i]=max(min(p[l*2-i],r-i),1);
    while(0<=i-p[i]&&i+p[i]<size(s)&&s[i-p[i]]==s[i+p[i]]){
      l=i,r=i+p[i],p[i]++;
    }
  }
  return p;
}
