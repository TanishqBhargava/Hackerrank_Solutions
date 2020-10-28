/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
long long values[10000001];

int main() 
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) 
    {
        int l, r, k;
        cin >> l >> r >> k;
        --l;
        values[l] += k;
        values[r] -= k;
    }
    long long cur = 0, ans = 0;
    for (int i = 0; i < n; ++i) 
    {
        cur += values[i];
        ans = max(ans, cur);
    }
    cout << ans << endl;
}
