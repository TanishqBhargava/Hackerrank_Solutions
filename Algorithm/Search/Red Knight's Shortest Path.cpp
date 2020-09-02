#include <iostream>

int abs(int i){ return i<0? -i:i; }

bool both_hex(int di, int dj){
  if(di&1) return false;
  else if(di%4==0) return !(dj&1);
  else return dj&1;
}

void case1(int di, int dj){
  std::cout << abs(di)/2+(abs(dj)-abs(di)/2)/2 << '\n';
  if(di<=0 && dj>0){
    while(di){
      di+=2;
      --dj;
      std::cout << "UR ";
    }
    while(dj){
      dj-=2;
      std::cout << "R ";
    }
  }else if(di<=0 && dj<0){
    while(di){
      di+=2;
      ++dj;
      std::cout << "UL ";
    }
    while(dj){
      dj+=2;
      std::cout << "L ";
    }
  }else if(di>0 && dj>0){
    while(abs(di)!=2*abs(dj)){
      dj-=2;
      std::cout << "R ";
    }
    while(di){
      di-=2;
      --dj;
      std::cout << "LR ";
    }
  }else{
    while(di){
      di-=2;
      ++dj;
      std::cout << "LL ";
    }
    while(dj){
      dj+=2;
      std::cout << "L ";
    }
  }
}

void case2(int n, int is, int js, int ie, int je){
  std::cout << abs(ie-is)/2 << '\n';
  while(ie<is){
    if(js==0 || abs(ie-is)==2*abs(je-js)){
      is-=2;
      ++js;
      std::cout << "UR ";
    }else{
      is-=2;
      --js;
      std::cout << "UL ";
    }
  }
  while(ie>is){
    if(js==n-1 || abs(ie-is)==2*abs(je-js)){
      is+=2;
      --js;
      std::cout << "LL ";
    }else{
      is+=2;
      ++js;
      std::cout << "LR ";
    }
  }
}

void knight(int n, int is, int js, int ie, int je){
  if(abs(ie-is)<=2*abs(je-js)){
    case1(ie-is, je-js);
  }else case2(n, is, js, ie, je);
}

void solve(){
  int n=0, is=0, js=0, ie=0, je=0;
  std::cin >> n >> is >> js >> ie >> je;
  if(both_hex(abs(is-ie),abs(js-je))) knight(n,is,js,ie,je);
  else std::cout << "Impossible";
}

int main(){
  solve();
}
