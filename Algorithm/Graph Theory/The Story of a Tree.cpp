/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
long long a,s,d[100002],f[100002],g,h,j,k,l,i,n,m;
vector<int> v[100002];

void dfs(int idx,int par)
{
    d[idx] = par;
    for(auto it:v[idx])
    {
        if(it == par) 
            continue;
        dfs(it, idx);
    }
}

void df1(int idx)
{
    l += f[idx];
    if(l >= k) 
        g++;
    for(auto it:v[idx])
    {
        if(it == d[idx]) 
            continue;
        df1(it);
    }
    l -= f[idx];
}
int main()
{
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++)
    {
        cin >> n;
        for(i = 1; i <= n; i++)
            v[i].clear();
        memset(f, 0, sizeof f);
        g = 0;
        l = 0;
        for(i = 0; i < n - 1; i++)
        {
            cin >> a >> s;
            v[a].push_back(s);
            v[s].push_back(a);
        }
        dfs(1, 0);
        cin >> m >> k;
        for(i = 0; i < m; i++)
        {
            cin >> a >> s;
            if(d[s] == a) 
            {
                f[s]--;
                l++;
            }
            else 
                f[a]++;
        }
        df1(1);
        if(g==0) 
            cout << "0/1\n";
        else 
            cout << g/__gcd(g,n) << "/" << n/__gcd(g,n) << endl;
    }
    return 0;
}
