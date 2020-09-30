/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(0); 
    cin.tie(0);
    int t; 
    cin >> t;
    for (int ts = 0; ts < t; ++ts)
    {
        int n, m; 
        cin >> n >> m;
        vector<vector<pair<int,int>>> adj (n + 1);
        for (int i = 0; i < m; ++i)
        {
            int a, b, r; 
            cin >> a >> b >> r;
            adj[a].push_back({b, r});
            adj[b].push_back({a, r});
        }
        int s; 
        cin >> s;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<bool> vis (n + 1);
        q.push({0, s});
        vector<int> ans (n + 1, -1);
        while (!q.empty())
        {
            int d = q.top().first, x = q.top().second;
            q.pop();
            if (vis[x]) 
                continue;
            vis[x] = true;
            ans[x] = d;
            for (int i = 0; i < adj[x].size(); ++i)
                q.push({d+adj[x][i].second,adj[x][i].first});
        }
        for (int i = 1; i <= n; ++i)
            if (i != s)
                cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}
