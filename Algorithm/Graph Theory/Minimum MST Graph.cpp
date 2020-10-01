/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int g;
ll n,m,s;

int main()
{
    cin >> g;
    while(g--)
    {
        cin >> n >> m >> s;
        if(m <= (n - 1ll) * (n - 2ll) / 2ll + 1ll)
        {
            cout << s+(m-n+1ll) << endl;
            continue;
        }
        ll mult=m-(n-1ll)*(n-2ll)/2ll;
        s -= (n-1ll);
        ll ans = m;
        ans += s / (n - 1ll) * min(m, mult * (n - 1ll));
        s %= (n - 1ll);
        if(s) ans += min(mult * s,((n - 2ll) + (n - s)) * (s - 1ll) / 2ll + mult);
        cout << ans << endl;
    }
    return 0;
}
