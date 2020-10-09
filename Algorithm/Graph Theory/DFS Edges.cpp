/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vvi;
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair
vvi ans;

void go(ll n, ll b, ll f, ll c, ll add) 
{
    if(n == 1)
        return;
    if(c >= n - 2) 
    {
        int b1 = b;
        if(b > 0)
            b1--;
        go(n - 1, b1, f, c - n + 2, add);
        ans[add].pb(add + n - 1);
        forn(i, 1, n - 1) 
            ans[add + n - 1].pb(add + i);
        if(b1 < b)
            ans[add + n - 1].pb(add);
    } 
    else 
    {
        ans[add].pb(add + 1);
        go(n - 1, max(0ll, b - n + 1), max(0ll, f - n + 2), c, add + 1);
        forn(i, 0, min(n - 1, b)) 
            ans[add + i + 1].pb(add);
        forn(i, 0, min(n - 2, f)) 
            ans[add].pb(add + i + 2);
    }
}

int main() 
{
    ll t, b, f, c;
    cin >> t >> b >> f >> c;
    ll n = t + 1, in = max(t + f, b);
    ans.resize(n);
    if(in + c > (n * (n - 1)) / 2) 
    {
        cout << -1;
        return 0;
    }
    go(n, b, f, c, 0);
    cout << n << endl;
    forn(i, 0, n)
    {
        cout << ans[i].size();
        for (auto x : ans[i])
            cout << " " << x + 1;
        cout << endl;
    }
    return 0;
}
