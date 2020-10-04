/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn = 100010 , Maxm = 11, Mo = 1e9 + 7;
const ll oo = 1ll << 60;
#define PB push_back
int T, cs = 1, n , m , k, cnt[Maxn];
vector<int> e[Maxn];

int main()
{
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v;
        e[u].PB(v);
        e[v].PB(u);
    }
    ll ans = 0;
    for (int u = 1; u <= n; u++)
    {
        vector<int> all;
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i];
            for (int k =0; k < e[v].size(); k++)
            {
                int t = e[v][k];
                if (t == u) 
                    continue;
                if (cnt[t] == 0) 
                    all.PB(t);
                ans += cnt[t];
                cnt[t] ++;                
            }
        }
        for (int i = 0; i < all.size(); i++) cnt[all[i]] = 0;
    }
    cout << ans / 4 << endl;
}
