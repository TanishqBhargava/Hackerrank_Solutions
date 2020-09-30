/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
bool us[114514][10];
vector<P> G[114514];

int main()
{
    ll ans[10] = {};
    ll n, e;
    cin >> n >> e;
    for(ll i = 0; i < e; i++)
    {
        ll x, y, r;
        cin >> x >> y >> r;
        x--;
        y--;
        G[x].push_back(P(y,r % 10));
        G[y].push_back(P(x,(1000 - r) % 10));
    }
    for(ll i=0;i<n;i++)
    {
        ll f = 0;
        for(ll j = 0; j < 10; j++) 
            f|= us[i][j];
        if(f) 
            continue;
        ll tmp[10] = {};
        set<ll> s;
        queue<P> q;
        q.push(P(i,0));
        while(!q.empty())
        {
            P p = q.front();
            q.pop();
            ll v = p.first,d = p.second;
            if(us[v][d]) 
                continue;
            s.insert(v);
            us[v][d]=1;
            tmp[d]++;
            for(ll j=0;j<(ll)G[v].size();j++)
            {
                ll u = G[v][j].first,nd = (d + G[v][j].second) % 10;
                if(!us[u][nd]) q.push(P(u,nd));
            }
        }
        for(auto j:s)
        {
            for(ll k = 0; k < 10; k++) 
                tmp[k] -= us[j][k];
            for(ll k = 0; k < 10; k++)
            {
                if(us[j][k])
                {
                    for(ll l = 0; l < 10; l++)
                    {
                        ans[(l + 10 - k) % 10] += tmp[l];
                    }
                    break;
                }
            }
            for(ll k=0;k<10;k++) tmp[k]+=us[j][k];
        }
    }
    for(ll i=0;i<10;i++) cout<<ans[i]<<endl;
    return 0;
}
