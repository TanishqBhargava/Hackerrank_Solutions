/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
#define task "vosplay"
#define forinc(a, b, c) for(int a = b; a <= c; ++a)
#define reset(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
using namespace std;
const int N=100010;
int n, m, q, a[N], c[N], id[N], ans[N];
unordered_map<int,int> f[N];

int root(int x)
{
    return id[x]<0?x:id[x]=root(id[x]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    forinc(i, 1, n) cin >> a[i], c[a[i]]++, f[i][a[i]] = 1;
    reset(ans, -1);
    reset(id, -1);
    forinc(i, 1, q)
    {
        int x, y;
        cin >> x >> y;
        if((x = root(x)) == (y = root(y))) 
            continue;
        if(id[x] > id[y]) 
            swap(x, y);
        id[x] += id[y];
        id[y] = x;
        for(auto&u:f[y])
        {
            f[x][u.fi] += u.se;
            if(f[x][u.fi] == c[u.fi]) 
                ans[u.fi] = i;
        }
    }
    forinc(i, 1, m) if(c[i] == 1) ans[i] = 0;
    forinc(i, 1, m) cout << ans[i] << endl;
}
