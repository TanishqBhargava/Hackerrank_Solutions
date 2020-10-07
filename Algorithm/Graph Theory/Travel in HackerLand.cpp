/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;

ll powmod(ll a, ll b) 
{
    ll res = 1;
    a %= mod; 
    assert(b >= 0); 
    for(; b; b>>=1)
    {
        if(b&1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

const int N = 101000;
map<int,int> pr[N],sz[N];
set<int> col[N],st[N];
int T, n, m, q, ty[N], u, v, w, k;
vector<pair<int,PII> > e;

int Pr(int u) 
{
    return (--pr[u].upper_bound(T))->se;
}

bool check(int x) 
{
    T = x;
    if (Pr(u) != Pr(v)) 
        return 0;
    return (--sz[Pr(u)].upper_bound(x))->se>=k;
}

int main() 
{
    cin >> n >> m >> q;
    rep(i,1,n+1) cin >> ty[i];
    rep(i,0,m) 
    {
        cin >> u >> v >> w;
        e.pb(mp(w,mp(u,v)));
    }
    sort(all(e));
    rep(i, 1, n + 1) pr[i][0] = i, sz[i][0] = 1;
    rep(i, 1, n + 1) col[i].insert(ty[i]), st[i].insert(i);
    rep(i, 0, SZ(e)) 
    {
        int u = e[i].se.fi,v = e[i].se.se;
        T++; 
        u = Pr(u); 
        v = Pr(v);
        if (u != v) 
        {
            if (SZ(st[u]) > SZ(st[v])) 
            {
                for (auto c:st[v]) 
                    pr[c][T] = u, st[u].insert(c);
                for (auto c:col[v]) 
                    col[u].insert(c);
                sz[u][T] = SZ(col[u]);
            } 
            else 
            {
                for (auto c:st[u]) 
                    pr[c][T] = v, st[v].insert(c);
                for (auto c:col[u]) 
                    col[v].insert(c);
                sz[v][T] = SZ(col[v]);
            }
        }
    }
    rep(i, 0, q) 
    {
        cin >> u >> v >> k;
        if (!check(m)) 
            puts("-1");
        else 
        {
            int l = 0,r = m;
            while (l + 1 < r) 
            {
                int md = (l + r)>>1;
                if (!check(md)) 
                    l = md; 
                else 
                    r = md;
            }
            cout << e[r-1].fi << endl;
        }
    }
}
