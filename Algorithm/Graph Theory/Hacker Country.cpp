/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    return (long long)a.first * b.second < (long long)b.first * a.second;
}

int main()
{
    const int INF = 0x3f3f3f3f;
    int n; 
    cin >> n;
    int adj_mat[n + 1][n + 1];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj_mat[i][j];
    for(int i = 0; i <= n; i++) 
        adj_mat[i][i] = INF;
    for(int i = 0; i < n; i++)
        adj_mat[n][i] = 0, adj_mat[i][n] = INF;
    int dp[n + 2][n + 2];
    memset(dp, INF, sizeof dp);
    dp[0][n] = 0;
    for(int k = 0; k <= n; k++)
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                if(dp[k + 1][j] > dp[k][i] + adj_mat[i][j])
                    dp[k + 1][j] = dp[k][i] + adj_mat[i][j];
    pair<int, int> res = make_pair(INF, 1);
    for(int i = 0; i < n; i++)
    {
        if(dp[n + 1][i] == INF) 
            continue;
        pair<int, int> mx = make_pair(-INF, 1);
        for(int k = 0; k < n; k++)
        {
            if(dp[k][i] == INF) 
                continue;
            pair<int, int> curr = make_pair(dp[n + 1][i] - dp[k][i], n + 1 - k);
            if(compare(mx, curr)) 
                mx = curr;
        }
        if(compare(mx, res)) 
            res = mx;
    }
    int g = __gcd(res.first, res.second);
    cout << res.first/g << "/" << res.second/g << endl;
    return 0;
}
