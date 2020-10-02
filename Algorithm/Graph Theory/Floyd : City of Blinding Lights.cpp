/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include<bits/stdc++.h>
using namespace std;
int i, j, k, n, q;
long long dp[405][405];

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    for(i = 0; i <= 403; ++i)
        for(j = 0; j <= 403; ++j)
            dp[i][j] = 1e15;
        for(cin >> n >> q; q; --q) 
            cin >> i >> j >> k,dp[i][j] = k;
    for(k = 1; k <= n; ++k)
        for(i = 1; i <= n; ++i)
            for(j = 1; j <= n; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            for(i = 1; i <= n; ++i) 
                dp[i][i] = 0;
            for(cin >> q ; q; --q) 
                cin >> i >> j, cout << (dp[i][j] >= 1e14 ? -1:dp[i][j]) << endl;
    return 0;
}
