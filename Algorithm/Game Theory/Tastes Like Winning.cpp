#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef long double ld;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int mod = 1000000007;

ll mpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return res;
}

int stupid(int n, int m) {
    int c = 0;
    int all = (1 << m) - 1;
    for (int mask = 1; mask < (1 << all); ++mask) if (__builtin_popcount(mask) == n) {
        int xr = 0;
        for (int i = 0; i < all; ++i) if (mask & (1 << i)) {
            xr ^= 1 + i;
        }
        if (xr) ++c;
    }
    for (int i = 2; i <= n; ++i) c = c * (ll)i % mod;
    return c;
}

int solve(int n, int m) {
    vi d(n + 1);
    vi a(n + 1);
    d[0] = 1;
    d[1] = 0;
    ll dif = mpow(2, m) - 1;
    a[0] = 1;
    for (int i = 1; i <= n; ++i) a[i] = a[i-1] * (dif - i + 1) % mod;
    for (int i = 2; i <= n; ++i) {
        d[i] = (a[i-1] - d[i-2] * (dif - i + 2) % mod * (i-1) - d[i-1]) % mod;
        //cerr << i << ' ' << d[i] << endl;
    }
    return (a[n] - (ll)d[n] + 2*mod) % mod;
}

int main() {
    int n,m;
    cin >> n >> m;
    cout << solve(n, m) << endl;
    //cerr << stupid(n,m) << ' ' << a[n] << endl;
    return 0;
}
