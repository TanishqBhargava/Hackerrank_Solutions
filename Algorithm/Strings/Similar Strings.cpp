#include <bits/stdc++.h>
#define mo(x) ((x)<P?(x):(x)-P)
using namespace std;
const int N=100009;
const int C=10;
const long long P=pow(10,9)+97;
int n,m;
char c[N*2];
int a[N][C],v[N],v2[N];
long long b[N][C],p[N];

void input(){
    scanf("%d%d",&n,&m);
    assert(1<=min(n,m)&& max(n,m)<=50000);
    scanf("%s",c+1);
}

int getmax(int x,int y){
    if (x>y) swap(x,y);
    int r=n-y+1;
    int l=0,mi,h=0;
    while (l<r){
        mi=(l+r+1)/2;
        h=0;
        for (int i=0;h==i && i<C;i++)
          h+=(((b[x+mi-1][a[x][i]]
               -b[x   -1][a[x][i]])*p[y-x]
               -b[y+mi-1][a[y][i]]
               +b[y   -1][a[y][i]])%P==0);
        if (h==C) l=mi; else r=mi-1;
    }
    return l;
}

bool sufcomp(int x,int y){
    int d=getmax(x,y);
    if (d==n-max(x,y)+1)
        return x>y;
    int _A=0,_B=0;
    for (int i=0;i<C;i++){
        if (c[x+d]==a[x][i]) _A=i;
        if (c[y+d]==a[y][i]) _B=i;
    }
    return _A<_B;
}

void pre(){
    p[0]=1;
    for (int i=1;i<N;i++) p[i]=p[i-1]*5021%P;

    for (int i=1;i<=n;i++) c[i]-='a';
    for (int i=0;i<C;i++) a[n+1][i]=i;
    for (int i=n;i>0;i--){
        int I=0;
        for (int j=0;j<C;j++){
            a[i][j]=a[i+1][j];
            if (a[i][j]==c[i])  I=j;
        }
        while (I--) swap(a[i][I],a[i][I+1]);
    }

    for (int i=1;i<=n;i++){
        b[i][c[i]]=p[i];
        for (int j=0;j<C;j++)
            b[i][j]=mo(b[i][j]+b[i-1][j]);
    }

    for (int i=1;i<=n;i++) v[i]=i;
    stable_sort(v+1,v+n+1,sufcomp);
    for (int i=1;i<=n;i++) v2[v[i]]=i;
}

void sol(){
    pre();
    while (m--){
        int l,r,mi;
        scanf("%d%d",&l,&r);
        int x=v2[l];
        int d=r-l+1;
        l=1;
        r=x;
        while (l<r){
            mi=(l+r)/2;
            if (getmax(v[x],v[mi])<d)
                l=mi+1;
            else
                r=mi;
        }
        int L=l;
        l=x;
        r=n;
        while (l<r){
            mi=(l+r+1)/2;
            if (getmax(v[x],v[mi])<d)
                r=mi-1;
            else
                l=mi;
        }
        int R=l;
        printf("%d\n",R-L+1);
    }
}

int main() {
    input();
    sol();
    return 0;
}
