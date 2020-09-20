#include <bits/stdc++.h>
using namespace std;
int a[105], p, q, n, best = -1, ans;
int main()
{
    cin >> n;
    for(int x = 0; x < n; x++) cin >> a[x];
    cin >> p >> q;
    ans = p;
    sort(a, a + n);
    if(p <= a[0]) best = a[0] - p;
    for(int x = 0; x < n - 1; x++)
    {
        if(p > a[x+1] || q < a[x]) continue;
        int m = (a[x] + a[x + 1]) / 2;
        if(m - a[x] <= best) continue;
        if(p <= m && m <= q){best = m - a[x]; ans = m;}
        else if(p >= a[x]){if(a[x+1] - p > best){best = a[x+1] - p; ans = p;}}
        else if(q - a[x] > best){best = q - a[x]; ans = q;}
    }
    if(q >= a[n-1] && q - a[n-1] > best) ans = q;
    cout << ans;
    return 0;
}
