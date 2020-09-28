#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool vis[100005];
int c;

void solve (int i) 
{
    if ( vis[i] ) 
        return;
    vis[i] = 1; 
    c++;
    for (int j = 0; j < adj[i].size(); j++)
        solve( adj[i][j] );
}

int main ()
{
    int q; 
    cin >> q;
    while (q--) 
    {
        long long n,m,clib,croad,ans=0;
        cin >> n >> m >> clib >> croad;
        for (int i = 0; i <= n; i++) 
            adj[i].clear(), vis[i] = 0;
        int u,v;
        while (m--) 
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) 
        {
            if ( vis[i] ) 
                continue;
            c = 0;
            solve(i);
            ans += (c-1)*croad + clib;
        }
        ans = min( ans , n*clib );
        cout << ans << endl;
    }
}
