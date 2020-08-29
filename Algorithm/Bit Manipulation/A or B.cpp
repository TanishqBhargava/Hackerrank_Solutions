#include <iostream>
#include <string>
#include <ios>

using std::string;

int ord(const char c){ return c>='A'?10+c-'A':c-'0'; }
char chr(const int i){
  return static_cast<char>(i<10?'0'+i:'A'+(i-10));
}

bool process(const int (&res)[8], const int (&count)[8], int &k, string &a, string &b, const string &c, const bool must_afford){
  const int n=a.size();
  for(int i=0;i<n;++i){
    const int aval0=ord(a[i]), bval0=ord(b[i]), cval=ord(c[i]);
    int aval1=0, bval1=0;
    for(int j=4-1;j!=-1;--j){
      int key=0;
      key|=(1&(aval0>>j))<<2;
      key|=(1&(bval0>>j))<<1;
      key|=1&(cval>>j);
      int r=res[key];
      if(k<count[key]){
    if(must_afford) return false;
    r=key;
      }else k-=count[key];
      aval1|=(1&(r>>2))<<j;
      bval1|=(1&(r>>1))<<j;
    }
    a[i]=chr(aval1);
    b[i]=chr(bval1);
  }
  return true;
}

bool solve(int k, string &a, string &b, const string &c){
  const int mand_res[]={0,3,0,3,0,5,0,7};
  const int mand_count[]={0,1,1,0,1,0,2,0};
  const int opt_res[]={0,1,2,3,4,3,6,3};
  const int opt_count[]={0,0,0,0,0,2,0,1};
  if(!process(mand_res,mand_count,k,a,b,c,true)) return false;
  process(opt_res,opt_count,k,a,b,c,false);
  return true;
}

void pad(string &s, const int sz){
  if(s.size()<sz){
    s=string(sz-s.size(),'0')+s;
  }
}

int larger(const int a, const int b){return a>b?a:b;}

void equalize(string &a, string &b, string &c){
  const int sz=larger(a.size(),larger(b.size(),c.size()));
  pad(a,sz);
  pad(b,sz);
  pad(c,sz);
}

void print_hex(const string &a){
  int i=0;
  for(;i<a.size() && a[i]=='0';++i);
  if(i==a.size()) std::cout << "0\n";
  else std::cout << a.substr(i) << '\n';
}

int main(){
  std::ios_base::sync_with_stdio(false);
  int q=0;
  std::cin >> q;
  while(q--){
    int k=0;
    string a,b,c;
    std::cin >> k >> a >> b >> c;
    equalize(a,b,c);
    if(solve(k,a,b,c)){
      print_hex(a);
      print_hex(b);
    }else std::cout << "-1\n";
  }
}
