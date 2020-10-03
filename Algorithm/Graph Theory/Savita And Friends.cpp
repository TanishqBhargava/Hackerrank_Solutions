/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )
#define eb emplace_back
#define fi first
#define se second

int ri()
{
    int x;
    cin >> x;
    return x;
}

const int N = 100000;
bool vis[N];
ll d0[N], d1[N];
pll a[N];
vector<pii> es[N];

void dijkstra(int n, int src, ll d[])
{
    fill_n(vis, n, false);
    fill_n(d, n, LLONG_MAX/3);
    d[src] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.emplace(0, src);
    while (! pq.empty()) 
    {
        pli x = pq.top();
        pq.pop();
        if (vis[x.se]) 
            continue;
        vis[x.se] = true;
        for (pii e: es[x.se])
            if (x.fi+e.se < d[e.fi])
                pq.emplace(d[e.fi] = x.fi+e.se, e.fi);
    }
}

int main()
{
    for (int cc = ri(); cc--; ) 
    {
        int n = ri(), m = ri(), k = ri()-1, x, y, z;
        REP(i, n)
            es[i].clear();
        REP(i, m) 
        {
            int u = ri() - 1, v = ri() - 1, w = ri();
            if (i == k)
                x = u, y = v, z = w;
                es[u].eb(v, w);
                es[v].eb(u, w);
        }
        dijkstra(n, x, d0);
        dijkstra(n, y, d1);
        REP(i, n)
            a[i] = {d0[i], d1[i]};
        sort(a, a+n);
        ll ans0 = 0, ans1 = 2 * a[n - 1].fi;
        int p = n - 1;
        ROF(i, 0, n - 1)
            if (a[i].se > a[p].se) 
            {
                ll t = a[i].fi + a[p].se + z;
                if (t < ans1)
                    ans0 = a[p].se + z - a[i].fi, ans1 = t;
                p = i;
            }
            ll t = 2 * a[p].se;
            if (t < ans1)
                ans1 = t, ans0 = 2 * z;
            cout << fixed << setprecision(5) << ans0 * 0.5 << " " << ans1 * 0.5 << endl;
    }
}
