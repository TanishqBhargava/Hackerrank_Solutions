#include <iostream>
#include <vector>
#include <ios>

int abs(int x){ return x<0?-x:x; }
int main(){
  std::ios_base::sync_with_stdio(false);
  int t=0; std::cin >> t;
  while(t--){
    int n=0; std::cin >> n;
    std::vector<int> r1;
    for(int i=0;i<n;++i){
      int r=0; std::cin >> r;
      r1.push_back(r);
    }
    int total=0;
    for(int i=0;i<n;++i){
      int r2=0; std::cin >> r2;
      total^=abs(r2-r1[i])-1;
    }
    std::cout << (total?"player-2\n":"player-1\n");
  }
}
