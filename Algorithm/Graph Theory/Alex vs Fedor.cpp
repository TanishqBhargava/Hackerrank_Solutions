/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;

inline char nc() 
{
    static char buf[100000], *l = buf, *r = buf;
    return l == r && (r = (l = buf) + fread(buf, 1, 10000, stdin), l == r)?EOF:*l++;
}

template<class T> void read(T & x) 
{
    x = 0; 
    int f = 1, ch = nc();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-')
            f = -1;
            ch = nc();
    }
    while(ch >= '0' && ch <= '9') 
    { 
        x = x * 10 -'0' + ch;
        ch = nc();
    }
    x *= f;
}

typedef long long ll;
const int maxn = 100 + 5;
const int maxm = 100 + 5;
int n, m;
ll c[maxn][maxn];
int fa1[maxn], fa2[maxn], vis[maxn], adj[maxn][maxn];
vector<int> r[maxn];

struct data 
{
    int u, v, w;
    data(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}
    bool operator < (const data & other) const 
    {
        return w < other.w;
    }
} e[maxm];

ll myabs(ll a) 
{
    return a < 0 ? -a : a;
}

ll gcd(ll a, ll b) 
{
    return b ? gcd(b, a % b) : a;
}

int find(int a, int *fa) 
{
    return a == fa[a] ? a : fa[a] = find(fa[a], fa);
}

ll det(int n) 
{
    ll re = 1;
    for(int i = 1; i <= n; ++i) 
    {
        if(!c[i][i]) 
        {
            int k = -1;
            for(int j = i + 1; j <= n; ++j) 
            {
                if(c[j][i]) 
                {
                    k = j; 
                    break;
                }
            }
            if(k == -1) 
                return 0;
            for(int j = i; j <= n; ++j) 
            {
                swap(c[i][j], c[k][j]);
            }
            re = -re;
        }
        for(int j = i + 1; j <= n; ++j) 
        while(c[j][i]) 
        {
            ll d = c[i][i] / c[j][i];
            for(int h = i; h <= n; ++h) 
            {
                c[i][h] -= c[j][h] * d;
                swap(c[i][h], c[j][h]);
            }
            re = -re;
        }
        re = re * c[i][i];
    }
    return re;
}

ll solve1() 
{
    ll re = 1;
    sort(e + 1, e + m + 1);
    for(int i = 1; i <= n; ++i) 
    {
        fa1[i] = fa2[i] = i;
    }
    for(int i = 1; i <= m; ++i) 
    {
        int u = find(e[i].u, fa1), v = find(e[i].v, fa1);
        if(u != v) 
        {
            vis[u] = vis[v] = 1;
            adj[u][v]++, adj[v][u]++;
            u = find(u, fa2), v = find(v, fa2);
            if(u != v) 
                fa2[u] = v;
        }
        if(i == m || e[i].w != e[i + 1].w) 
        {
            for(int j = 1; j <= n; ++j) 
            if(vis[j]) 
            {
                r[find(j, fa2)].push_back(j);
            }
            for(int j = 1; j <= n; ++j) 
            if(r[j].size()) 
            {
                int l = r[j].size();
                memset(c, 0, sizeof(c));
                for(int a = 0; a < l; ++a) 
                {
                    for(int b = a + 1; b < l; ++b) 
                    {
                        int x = r[j][a], y = r[j][b];
                        c[a][b] -= adj[x][y], c[b][a] -= adj[x][y];
                        c[a][a] += adj[x][y], c[b][b] += adj[x][y];
                    }
                }
                re *= myabs(det(l - 1));
            }
            for(int i = 1; i <= n; ++i) 
                r[i].clear();
            memset(vis, 0, sizeof(vis));
            memset(adj, 0, sizeof(adj));
            memcpy(fa1, fa2, sizeof(fa2));
        }
    }
    return re;
}

ll solve2() 
{ 
    memset(c, 0, sizeof(c));
    for(int i = 1; i <= m; ++i) 
    {
        int u = e[i].u, v = e[i].v;
        c[u][v]--, c[v][u]--;
        c[u][u]++, c[v][v]++;
    }
    return myabs(det(n - 1));
}
int main() 
{
    read(n), read(m);
    for(int i = 1; i <= m; ++i) 
    {
        read(e[i].u), read(e[i].v), read(e[i].w);
    }
    ll a = solve1(), b = solve2();
    if(!b) 
        puts("0/0");
    else 
    {
        ll d = gcd(a, b); 
        a /= d, b /= d;
        cout << a << '/' << b << endl;
    }
    return 0;
}
