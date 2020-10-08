/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
int f[505][505], ans[505][505], mod = 1000000007;

int main() 
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) 
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a; 
        --b;
        f[a][b] += c;
        f[b][a] += c;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ans[i][j] = mod + 1;
    for (int a = 0; a < n; ++a) 
    {
        for (int b = a; b < n; ++b) 
        {
            int cut = 0;
            for (int i = 0; i < n; ++i) 
            {
                if (i == a || i == b) 
                    continue;
                cut += f[a][i];
                if (a != b) 
                    cut += f[b][i];
            }
            for (int i = 0; i < n; ++i) 
            {
                if (i == a || i == b) 
                    continue;
                ans[a][i] = min(ans[a][i], cut);
                ans[b][i] = min(ans[b][i], cut);
                ans[i][a] = min(ans[i][a], cut);
                ans[i][b] = min(ans[i][b], cut);
            }
        }
    }
    int ret = 1;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            ret = 1LL * ret * ans[i][j] % mod; 
    cout << ret << endl;
    return 0;
}
