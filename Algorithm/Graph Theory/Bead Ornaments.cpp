/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
int n, test, x, a[20];

ll power(ll x,int y)
{
    if (y == 0) 
        return 1;
    if (y == 1) 
        return x;
    ll tmp = power(x, y / 2);
        return (((tmp * tmp) % MOD) * power(x, y % 2)) % MOD;
}

int main() 
{
    cin >> test;
    while (test--)
    {
        cin >> n;
        ll way = 1,sum = 0;
        for(int i = 1; i <= n; i++) 
            cin >> a[i],sum += a[i];
        if (n > 1) 
        {
            way = (way * power(sum,n - 2)) % MOD;
            for(int i = 1; i <= n; i++) 
                way = (way * power(a[i], a[i] - 1)) % MOD;
        }
        else if (a[1] > 1) 
            way = power(a[1], a[1] - 2);
        cout << way << endl;
    }
    return 0;
}
