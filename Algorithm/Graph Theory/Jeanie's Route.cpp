/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
const int Maxn = 1e5 + 1;
using namespace std;
int n, k, x, y, z, G[Maxn], good[Maxn], pr[Maxn], ans, pas, D, goodsub[Maxn];
vector <pair <int,int> > g[Maxn];

void dfs(int v, int p = 0)
{
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i].first != p)
            dfs(g[v][i].first, v), goodsub[v] |= goodsub[g[v][i].first];
    goodsub[v] |= good[v];
}

int dfs_for_diameter(int v, int p = 0)
{
    pair <int,int> S = {0, 0};
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i].first != p && goodsub[g[v][i].first])
        {
            ans += 2 * g[v][i].second;
            S.second = max(S.second, dfs_for_diameter(g[v][i].first, v) + g[v][i].second);
            if (S.second > S.first) swap(S.first, S.second);
        }
    D = max(D, S.first + S.second);
    return S.first;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> G[i];
        good[G[i]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    dfs(G[1]);
    dfs_for_diameter(G[1], 0);
    cout << ans - D;
}
