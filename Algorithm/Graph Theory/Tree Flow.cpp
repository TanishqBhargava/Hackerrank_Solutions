/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<pair<int, ll> > > a;

ll sumd(int x, int p, ll cd) 
{
    ll ans = cd;
    for(auto y:a[x]) 
    if(y.first != p) 
    {
        ans += sumd(y.first, x, cd + y.second);
    }
    return ans;
}

int main() 
{
    int i, n, x, y;
    ll w, d1, d2;
    cin >> n;
    a.resize(n + 1);
    for(i = 0; i < n - 1; i++) 
    {
        cin >> x >> y >> w;
        a[x].push_back(make_pair(y, w));
        a[y].push_back(make_pair(x, w));
    }
    d1=sumd(1, -1, 0);
    d2=sumd(n, -1, 0);
    cout << min(d1, d2) << endl;
    return 0;
}
