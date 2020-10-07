/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
#define N 2100000
int n, m, a, b, c, pp, i, len, till[N], Next[N], go[N], pre[N], fei[N], f[N];
long long dis[N];
bool vis[N],pc[N];

void add(int a,int b,int c, int d)
{
    Next[++len] = till[a];
    till[a] = len;
    go[len] = b;
    f[len] = c;
    fei[len] = d;
}

bool dfs(int k)
{
    vis[k] = true;
    pc[k] = true;
    for (int i = till[k]; i; i = Next[i])
        if (f[i]) 
        {
            if (dis[k] + fei[i] < dis[go[i]])
            {
                dis[go[i]] = dis[k] + fei[i];
                pre[go[i]] = i;
                if (!pc[go[i]])
                {
                    if (dfs(go[i]))    
                        return true;
                }
                else 
                {
                    pp = go[i];
                    return true;
                }
            }
        }
    pc[k] = false;
    return false;
}

int fi()
{
    int i;
    for (i = 1;i <= n; i++)    
        vis[i] = false, dis[i] = 0, pc[i] = false;
    for (i = 1; i <= n; i++)
    if (!vis[i] && dfs(i))    
        return i;
    return 0;
}

int main() 
{
    int T;
    cin >> T;
    while (T--) 
    {
        cin >> n >> m;
        len = 1;
        for (int i = 1; i <= n; i++)
            till[i] = 0;
        for (int i = 1; i < n; i++) 
        {
            cin >> a >> b >> c;
            add(a, b, c, 0);
            add(b, a, c, 0);
        }
        long long ans = 0;
        for (int i = 1; i <= m; i++) 
        {
            cin >> a >> b >> c;
            add(b, a, 1, -c);
            add(a, b, 0, c);
        }
        while (fi()) 
        {
            for (int i = pre[pp]; ; i = pre[go[i ^ 1]]) 
            {
                ans -= fei[i];
                f[i] -= 1;
                f[i ^ 1] += 1;
                if (go[i ^ 1] == pp)
                    break;
            }
        }
        cout << ans << endl;
    }
}
