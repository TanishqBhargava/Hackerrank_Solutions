/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include<bits/stdc++.h>
#define N 100005
using namespace std;
vector<int>a[N];
int deep[2][N], id, n, x, y, s, t, m, ma, o, k, i, v;

void dfs(int k,int fa,int dis)
{
    if (dis>ma)  
    {
        ma=dis;
        id=k;
    }
    for (int i=0;i<a[k].size();i++)
        if (a[k][i]!=fa) 
            dfs(a[k][i],k,dis+1);

}

void find(int k,int fa)
{
    for (int i=0;i<a[k].size();i++)
        if (a[k][i]!=fa) 
        {
            deep[o][a[k][i]]=deep[o][k]+1;
            find(a[k][i],k);
        }
}

int main()
{
    cin >> n >> m;
    for (i = 1; i < n; i++)
        cin >> x >> y, a[x].push_back(y), a[y].push_back(x);
    ma = 0; dfs(1, 0, 0); s = id;
    ma = 0; dfs(s, 0, 0); t = id;
    find(s, 0);
    o = 1;
    find(t, 0);
    while (m--)
    {
        cin >> k >> v;
        cout << max(deep[0][k],deep[1][k])+1ll*ma*(v-1) << endl;
    }
}
