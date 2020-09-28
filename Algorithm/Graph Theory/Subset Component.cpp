/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll a[25],ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,i,j,cnt,fp;
    ll num;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];
    for(i = 0; i < (1<<n); i++)
    {
        cnt = 0, num = 0ULL, fp = 0;
        for(j = i; j; j >>= 1, cnt++)
            if(j & 1)
            {
                if(a[cnt] && !(num & a[cnt]))
                    fp++;
                num|=a[cnt];
            }
        ans += 64 - __builtin_popcountll(num) + fp;
    }
    cout << ans;
    return 0;
}
