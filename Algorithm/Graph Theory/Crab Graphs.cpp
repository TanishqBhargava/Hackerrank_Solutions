/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int u, v, n, m, d, t, ncase, nr;
    for(cin >> ncase; ncase; ncase--) 
    {
        cin >> n >> t >> m;
        vector<vector<int> > a(n+1);
        for(; m; m--) 
        {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        nr = 0;
        for(u = 1; u <= n; u++) 
        {
            if(a[u].size() == 0) 
                nr++;
            d = 0;
            for(auto x:a[u]) 
                if(a[x].size()==1) 
                    d++;
            if(d > t) 
                nr += d - t;
        }
        cout << n-nr << endl;
    }
    return 0;
}
