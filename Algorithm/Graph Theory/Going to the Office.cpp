/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include<bits/stdc++.h>
#define INF 2000000000
#define NMAX 200005
using namespace std;
vector<vector<pair<int,int> > > adj(NMAX);
vector<int> depthlist[NMAX];
int dist[NMAX], dist1[NMAX], dist2[NMAX], answer[NMAX], parent[NMAX], depth[NMAX];
pair<int,int> top,temp;
priority_queue<pair<int,int> > pq;
set<pair<pair<int,int>,int> > se;

void dijkstra(int start)
{
    int i, size;
    fill(dist, dist + NMAX, INF);
    fill(parent, parent + NMAX, -1);
    dist[start] = 0;
    pq.push(make_pair(start, 0));
    while(!pq.empty()) 
    {
        top = pq.top();
        pq.pop();
        size = adj[top.first].size() ;
        if(top.second ==  dist[top.first])
            for(i = 0; i < size; i++)
            {
                temp = adj[top.first].at(i);
                if(dist[top.first] + temp.second < dist[temp.first])
                {
                    parent[temp.first] = top.first ;
                    dist[temp.first]  = dist[top.first] + temp.second ;
                    pq.push(make_pair(temp.first,dist[temp.first]));
                }
            }
    }
}

int getdepth(int v)
{
    return (depth[v] == -1)? (depth[v] = getdepth(parent[v])) : depth[v];
}

int main()
{
    int n, m, q, i, j, k, u, v, cst, s, d, ans;
    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        cin >> u >> v >> cst;
        adj[u].push_back(make_pair(v,cst));
        adj[v].push_back(make_pair(u,cst));
    }
    cin >> s >> d;
    dijkstra(d);
    for(i = 0; i < n; i++)
        dist2[i] = dist[i];
    dijkstra(s);
    for(i = 0; i < n; i++)
        dist1[i] = dist[i];
    fill(depth, depth + NMAX, -1);
    fill(answer, answer + NMAX, -1);
    for(i = d, j = NMAX - 1; i >= 0; depth[i] = j--, i = parent[i])
        if(depthlist[j].size() > 0)depthlist[j].clear();
    for(i = 0; i < n; i++)
        depthlist[getdepth(i)].push_back(i);
    for(i = depth[s]; i <= depth[d]; i++) 
    {
        for(j = 0; j < depthlist[i].size(); j++)
        {
            u = depthlist[i][j];
            for(k = 0 ; k < adj[u].size() ;k++ )
            {
                temp = adj[u][k];
                v = temp.first ;
                if(depth[u] == depth[v] || parent[u] == v || parent[v] == u) 
                    continue;
                if(depth[v] > depth[u])
                {
                    se.insert(make_pair(make_pair(dist1[u] + temp.second + dist2[v],u),v));
                }
                else
                    se.erase(se.find(make_pair(make_pair(dist1[v]+ dist2[u]+ temp.second,v),u)));
            }
        }
        if(se.size() != 0)
        answer[i] =  se.begin()->first.first;
    }
    cin >> q;
    while(q--)
    {
        cin >> u >> v;
        if((parent[u] == v || parent[v] == u ) && depth[u] != depth[v])
            ans = answer[min(depth[u],depth[v])];
        else
            ans = dist1[d];
        if(ans == -1) 
            cout << "Infinity" << endl;
        else 
            cout << ans << endl;
    }
return 0;
}
