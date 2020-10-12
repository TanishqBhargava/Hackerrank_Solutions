/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define sec second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
const ll INF = LLONG_MAX, MOD = 1e9+7;
const int N = 2e5;
ll t[N * 2];
ll n, d, q;
pll x[222222];
pll y[222222];

void upd(int p, int value) 
{  
    for (t[p += n] = value; p > 1; p >>= 1) 
        t[p>>1] = max(t[p], t[p^1]);
}

ll rmq(int l, int r) 
{  
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
    {
        if (l&1) res = max(res,t[l++]);
        if (r&1) res = max(res,t[--r]);
    }
    return res;
}

int main()  
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> q;
    while(q--)
    {
        cin >> n >> d;
        for(int i = 0; i < n; i++)
        {
            cin >> x[i].fst;
            x[i].sec = i;
        }
        sort(x, x + n);
        for(int i = 0; i < n; i++)
        { 
            y[x[i].sec] = {x[i].fst, i}; 
        }
        memset(t, 0, sizeof t);
        multimap<ll,int> a;
        for (int i = 0; i < n; ++i)
        {
            auto aa = a.insert(y[i]);
            if(aa != a.begin()) 
                upd(prev(aa)->sec, aa->fst-prev(aa)->fst);
            if(next(aa) != a.end()) 
                upd(aa->sec, next(aa)->fst-aa->fst);
            ll be = a.begin()->fst;
            ll en = a.rbegin()->fst;
            auto ii = a.lower_bound(en - d);
            auto jj = a.upper_bound(be + d);
            jj--;
            if(i == 0 || ii->fst>jj->fst)
            {
                cout << "0 "; 
                continue; 
            }
            ll ans = LLONG_MAX;
            if(en == jj->fst)
            {
                ii++;
                jj--;
            }
            ans = min(ans, jj->fst + d - en);
            ans = min(ans, be + d - ii->fst);
            ans = min(ans, be - en + d * 2 - rmq(ii->sec, jj->sec));
            cout << ans <<' ';
        }
        cout << endl;
    }
    cout.flush();
    return 0;
}
