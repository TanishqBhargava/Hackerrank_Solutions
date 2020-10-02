/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
int N,M;
const int MN = 1<<15;
vector<int> E[MN];
int color[MN];
typedef pair<int,bool> P;
P dp[MN];
const int Z = 1000000000;

P dfs(int n)
{
    if (n == N) 
        return P(1,1);
    if (color[n] == 1) 
        return P(-1, 0);
    if (color[n] == 2) 
        return dp[n];
    color[n] = 1;
    bool cycle = 0;
    bool found = 0;
    int r = 0;
    for(int t : E[n]) 
    {
        P p = dfs(t);
        int x = p.first;
        found |= p.second;
        if (x < 0) 
            cycle = 1;
        else 
            r = (r + x) % Z;
    }
    P p;
    p.first = cycle && found ? -1 : r;
    p.second = found;
    color[n] = 2;
    return dp[n] = p;
}

int main() 
{
    cin.sync_with_stdio(0);
    cin >> N >> M;
    for(int i = 0; i < M; ++i) 
    {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
    }
    P r = dfs(1);
    int x = r.first;
    if (x < 0) 
        cout << "INFINITE PATHS\n";
    else 
        cout << x << endl;
}
