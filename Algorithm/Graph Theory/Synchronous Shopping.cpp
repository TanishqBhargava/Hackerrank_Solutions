/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MOD 1000000007
#define MT make_tuple
#define PB push_back
typedef long long ll;
int N, M, K, T, a, s[1100], cost[1100][1100], mn=2e9;
bool seen[1100][1100];
vector<pair<int, int>> adj[1100];
priority_queue<pair<int, pair<int,int>>> q;

int main () 
{
    cin >> N >> M >> K;
    fo(i, 0, N) 
    {
        cin >> T;
        fo(j, 0, T) 
            cin >> a, s[i] += (1<<(a-1));
    }
    fo(z, 0, M) 
    {
        int i, j, k; 
        cin >> i >> j >> k;
        i--, j--;
        adj[i].PB({j, k}), adj[j].PB({i, k});
    }
    fo(i, 0, N) fo(j, 0, (1<<K)) cost[i][j] = 2e9;
    q.push({0, {0, s[0]}});
    while (q.size()) 
    {
        int c, i, j; 
        c = q.top().first, tie(i,j) = q.top().second, q.pop();
        if (seen[i][j]) 
            continue;
        seen[i][j] = 1, cost[i][j] = -c;
        for (auto g : adj[i]) 
        {
            if (!seen[g.first][j|s[g.first]]) 
            {
                q.push(make_pair(c - g.second, make_pair(g.first, j|s[g.first])));
            }
        }
    }
    fo(i, 0, (1<<K)) fo(j, 0, i) if ((j&i) == j) 
    {
        cost[N-1][j] = min(cost[N-1][j], cost[N-1][i]);
    }
    fo(i, 0, (1<<K)) 
        mn = min(mn, max(cost[N-1][i], cost[N-1][(1<<K) - 1 - i]));
    cout << mn << endl;
    return 0;
}
