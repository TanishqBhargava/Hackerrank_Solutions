/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
int n, k, num, c[100];
long long ans;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) 
        cin >> c[i];
    sort(c, c + n);
    ans = 0L;
    num = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        ans += (long long) num * c[i];
        if ((n - i) %k == 0) 
            num++;    
    }
    cout << ans << endl;
    return 0;
}
