#include <bits/stdc++.h>
using namespace std;

int n;
int c[1055];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
    cin >> c[i];
    long long res = 0ll;
    sort(c, c + n);
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) 
    res += 1ll * c[i] *  (1ll << cnt),cnt++;
    cout << res << endl;
    return 0;
}
