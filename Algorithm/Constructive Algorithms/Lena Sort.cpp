#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int t;
int n , c;
int arr[N];
int cur;
long long mx[N];
long long mn[N];
bool rekt;
void pre(){
    mx[0] = 0;
    for(int i = 1 ; i < N ; ++i){
        mx[i] = (1LL * i * (i - 1LL)) / 2LL;
    }
    mn[0] = 0;
    for(int i = 1 ; i < N ; ++i){
        mn[i] = i - 1 + mn[i - 1 >> 1] + mn[i - 1 - (i - 1 >> 1)];
    }
}
bool ok(int siz , int comps){
    if(comps < mn[siz] || comps > mx[siz]){
        return 0;
    }
    return 1;
}
bool solve(int siz , int comps , int start , int finish){
    if(!ok(siz , comps)){
        return 0;
    }
    if(siz < 1){
        return 1;
    }
    comps -= siz - 1;
    for(int i = 1 ; i <= siz ; ++i){
        int lft = i - 1;
        int rgt = siz - i;
        long long ql = mn[lft] + mn[rgt];
        long long qr = mx[lft] + mx[rgt];
        if(ql <= comps && comps <= qr){
            long long l = mn[lft];
            long long r = comps - l;
            if(r > mx[rgt]){
                long long extra = r - mx[rgt];
                r -= extra;
                l += extra;
            }
            arr[++cur] = start + i - 1;
            return solve(lft , l , start , start + i - 2) && solve(rgt , r , start + i , finish);
        }
    }
    return 0;
}
int main(){
    pre();
    scanf("%d" , &t);
    while(t--){
        scanf("%d %d" , &n , &c);
        cur = 0;
        rekt = 0;
        if(!solve(n , c , 1 , n)){
            printf("-1\n");
        }
        else{
            for(int i = 1 ; i <= n ; ++i){
                printf("%d%c" , arr[i] , " \n"[i == n]);
            }
        }
    }
}
