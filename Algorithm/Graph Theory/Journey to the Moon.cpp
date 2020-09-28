/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
vector<int> G[100000];
bool visited[100000] = {0};

int dfs(int i, int p) 
{
    if(visited[i]) return 0;
    int ret = visited[i] = 1;
    for(int j = 0; j < G[i].size(); j++)
        if(G[i][j] != p)
            ret += dfs(G[i][j], i);
    return ret;
}
int main() 
{
    int N, M;
    cin >> N >> M;
    while(M--) 
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    long long ans = N * (N - 1ll) / 2ll, t;
    for(int i = 0; i < N; i++)
        t = dfs(i, -1),
        ans -= t * (t - 1) / 2;
    cout << ans << endl;
    return 0;
}
