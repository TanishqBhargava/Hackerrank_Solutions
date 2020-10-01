/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
const long N = 34;
long a[N], adj[N];
unordered_map<long, pair<long, long>> m;

pair<long, long> rec(long cand)
{
    if (m.count(cand))
        return m[cand];
    auto& r = m[cand];
    if (! cand)
        r = {0, 1};
    else 
    {
        long i = __builtin_ctzl(cand);
        auto x = rec(cand & ~ (1L<<i) & ~ adj[i]), y = rec(cand & ~ (1L<<i));
        x.first += a[i];
        if (y.first > x.first)
            x = y;
        else if (y.first == x.first)
            x.second += y.second;
            r = x;
    }
    return r;
}

int main()
{
    long n, m, u, v;
    cin >> n >> m;
    REP(i, n)
        cin >> a[i];
    while (m--) 
    {
        cin >> u >> v;
        u--, v--;
        adj[u] |= 1L << v;
        adj[v] |= 1L << u;
    }
    auto r = rec((1L << n) - 1);
    cout << r.first << ' ' << r.second << endl;
}
