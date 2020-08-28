#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <utility>
#include <list>
#include <set>
#include <map>
using namespace std;

/****************SUFFIX ARRAY*********************/
#define MAXN 1000005
int n,t;  //n es el tamaño de la cadena
int p[MAXN],r[MAXN],h[MAXN];
//p es el inverso del suffix array, no usa indices del suffix array ordenado
//h el el tamaño del lcp entre el i-esimo y el i+1-esimo elemento de suffix array ordenado
string s;
void fix_index(int *b, int *e) {
   int pkm1, pk, np, i, d, m;
   pkm1 = p[*b + t];
   m = e - b; d = 0;
   np = b - r;
   for(i = 0; i < m; i++) {
      if (((pk = p[*b+t]) != pkm1) && !(np <= pkm1 && pk < np+m)) {
         pkm1 = pk;
         d = i;
      }
      p[*(b++)] = np + d;
   }
}

bool comp(int i, int j) {
   return p[i + t] < p[j + t];
}
void suff_arr() {
   int i, j, bc[256];
   t = 1;
   for(i = 0; i < 256; i++) bc[i] = 0;  //alfabeto
   for(i = 0; i < n; i++) ++bc[int(s[i])]; //counting sort inicial del alfabeto
   for(i = 1; i < 256; i++) bc[i] += bc[i - 1];
   for(i = 0; i < n; i++) r[--bc[int(s[i])]] = i;
   for(i = n - 1; i >= 0; i--) p[i] = bc[int(s[i])];
   for(t = 1; t < n; t *= 2) {
      for(i = 0, j = 1; i < n; i = j++) {
         while(j < n && p[r[j]] == p[r[i]]) ++j;
         if (j - i > 1) {
            sort(r + i, r + j, comp);
            fix_index(r + i, r + j);
         }
      }
   }
}
//Longest Common Preffix
void lcp() {
   int tam = 0, i, j;
   for(i = 0; i < n; i++)if (p[i] > 0) {
      j = r[p[i] - 1];
      while(s[i + tam] == s[j + tam]) ++tam;
      h[p[i]] = tam;
      if (tam > 0) --tam;
   }
   h[0] = 0;
}
/***************************************************/
int main(){
    int numS=0; scanf("%d",&numS);
    int res=numS;
    string sTemp;
    while(res--){
        cin>>sTemp;
        s +=sTemp+char(res+1);
    }
    n=s.size();
    suff_arr();
    lcp();
    vector<int> l(n);
    //Compute the l'
    for (int i = n-1,acum=1; i >= 0; --i)
    {
        if(s[i]<'a')
            acum=0;
        l[p[i]]=acum;
        acum++;

    }
    //for(int i=1;i<n;i++)cout<<"i -> "<<i<<" "<<s.substr(r[i])<<" "<<r[i]<<" "<<l[i]<<endl;
    //Queries
    int q;scanf("%d",&q);
    while(q--){
        int k,i=1;
         scanf("%d",&k);
         for (; i < n; ++i)
         {
             int comp = l[i]-h[i];
             if(comp>=k){
                 cout<<s.substr(r[i],h[i]+k)<<endl;
                 break;
             }else{
                 k-=comp;
             }
         }
         if(i==n)
             cout<<"INVALID"<<endl;
    }
   
   return 0;
}
