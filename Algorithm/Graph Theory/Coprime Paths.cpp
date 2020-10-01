/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i = j; i <= k; i++)
#define dow(i,j,k) for(register int i = j; i >= k; i--)
using namespace std;

inline int read() 
{
    int s = 0, t = 1; char c = getchar();
    while( !isdigit(c) ) 
    { 
        if( c == '-' ) 
        t = -1; 
        c = getchar(); 
    }
    while( isdigit(c) ) 
    s = s * 10 + c - 48, c = getchar();
    return s * t;
}

const int maxn = 3e4+5;
int B[maxn<<1], bl;

struct edge
{ 
    int to; 
    edge*next; 
} e[maxn<<1], *pt = e, *head[maxn];

inline void add(int x,int y) 
{
    pt->to = y, pt->next = head[x], head[x] = pt++;
    pt->to = x, pt->next = head[y], head[y] = pt++;
}

struct node
{
    int x, y, t, lca;
    node(int a=0,int b=0,int c=0,int d=0) 
    { 
        x = a, y = b, t = c, lca = d; 
    }
    bool operator < (const node&rhs) const 
    { 
        return B[x] != B[rhs.x] ? B[x] < B[rhs.x] : y < rhs.y; 
    }
} A[maxn];  
int v[maxn][3], len[maxn] = {0}, fa[maxn][15], bin[15] = {1};
const int N = 1e7+5, inf = 1e7;
int g[N], p[N/10], tot = 0; bool vis[N];

inline void pre() 
{
    int t; 
    rep(i,2,inf) 
    {
        if( !vis[i] ) g[p[++tot] = i] = i;
        for(register int j = 1; j <= tot && (t = p[j] * i) <= inf; j++) 
        {
            vis[t] = 1;
            if( i % p[j] == 0 ) 
            { 
                g[t] = g[i]; 
                break; 
            }
            g[t] = p[j];
        } 
    }
} 

int dep[maxn], L[maxn], R[maxn], ti = 0, pos[maxn<<1];
#define ez(i,j) for(edge*i = head[j]; i; i=i->next)
#define to i->to

inline void dfs(int x) 
{
    pos[L[x] = ++ti] = x;
    for(register int i = 1; 
        bin[i] <= dep[x]; i++) fa[x][i] = fa[fa[x][i-1]][i-1];
    ez(i,x) if( to != fa[x][0] ) dep[to] = dep[fa[to][0] = x] + 1, dfs(to);
    pos[R[x] = ++ti] = x;
}

bool f[maxn]; 
int ans[maxn], c[N], cnt = 0, Log[maxn];
#define lower(x) (x & -x)

inline int lca(int x,int y) 
{
    if( dep[x] < dep[y] ) swap(x,y);
    int t = dep[x] - dep[y];
    while( t ) 
        x = fa[x][Log[lower(t)]], t -= lower(t);
    if( x == y ) 
        return x;
    dow(i,14,0) if( fa[x][i] != fa[y][i] ) x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}

inline void update(int x) 
{
    int y, tot;
    if( f[x] ) 
    {
        f[x] = 0;
        rep(i,0,bin[len[x]]-1) 
        {
            y = 1, tot = 0;
            rep(j,0,len[x]) if( i & bin[j] ) y *= v[x][j], tot++;
            if( tot & 1 ) 
                cnt += ((--c[y]) << 1);
            else 
                cnt -= ((--c[y]) << 1);
        }
    } 
    else 
    {
        f[x] = 1;
        rep(i,0,bin[len[x]]-1) 
        {
            y = 1, tot = 0;
            rep(j,0,len[x]) if( i & bin[j] ) y *= v[x][j], tot++;
            if( tot & 1 ) 
                cnt -= ((c[y]++) << 1);
            else 
                cnt += ((c[y]++) << 1);
        }
    }
}

int main() 
{
    pre();
    int n = read(), m = read(), x, y, z;
    rep(i,1,14) bin[i] = bin[i-1] << 1;
    Log[0] = -1; rep(i,1,bin[14]) Log[i] = Log[i>>1] + 1; 
    rep(i,1,n) 
    {
        x = read();
        while( x != 1 ) 
        {
            v[i][len[i]++] = y = g[x];
            while( x % y == 0 ) x /= y;
        }
    }
    rep(i,1,n-1) add(read(),read());
    dfs(1), bl = sqrt(m);
    rep(i,1,ti) B[i] = (i-1) / bl + 1;
    rep(i,1,m) 
    {
        x = read(), y = read(), z = lca(x,y);
        if( L[x] > L[y] ) 
            swap(x,y);
        A[i] = node(x == z ? L[x] : R[x],L[y],i,x != z ? z : 0);
    }
    sort(A+1,A+m+1);
    int l = A[1].x, r = A[1].y;
    rep(i,l,r) update(pos[i]); 
    if( A[1].lca ) 
        update(A[1].lca);
    ans[A[1].t] = cnt;
    if( A[1].lca ) 
        update(A[1].lca);
    rep(i,2,m) 
    {
        x = A[i].x, y = A[i].y;
        while( x < l ) update(pos[--l]);
        while( r < y ) update(pos[++r]);
        while( x > l ) update(pos[l++]);
        while( y < r ) update(pos[r--]);
        if( A[i].lca ) update(A[i].lca);
        ans[A[i].t] = cnt;
        if( A[i].lca ) update(A[i].lca);
    }
    rep(i,1,m) cout << ans[i] / 2 << endl;
    return 0;
}
