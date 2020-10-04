/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> ii;
const int Maxn = 55;
const int MaxN = 5500;
const int Inf = 2000000000;

struct edge 
{
    int a, b, cap, cost;
    edge(int a = 0, int b = 0, int cap = 0, int cost = 0): 
        a(a), b(b), cap(cap), cost(cost) {}
};

vector <int> neigh[MaxN];
int n, k, R[Maxn][Maxn], C[Maxn][Maxn], id, N, dist[MaxN], par[MaxN];
char B[Maxn][Maxn];
vector <edge> E;

void addEdge(int a, int b, int cap, int cost)
{
    neigh[a].push_back(E.size()); E.push_back(edge(a, b, cap, cost));
    neigh[b].push_back(E.size()); E.push_back(edge(b, a, 0, -cost));
}

int getCost()
{
    fill(dist, dist + N, Inf); dist[0] = 0;
    priority_queue <ii> Q; Q.push(ii(-dist[0], 0));
    while (!Q.empty()) 
    {
        int v = Q.top().second, d = -Q.top().first; Q.pop();
        if (d != dist[v]) 
            continue;
        for (int i = 0; i < neigh[v].size(); i++) 
        {
            int e = neigh[v][i];
            if (E[e].cap > 0 && d + E[e].cost < dist[E[e].b]) 
            {
                dist[E[e].b] = d + E[e].cost;
                par[E[e].b] = e;
                Q.push(ii(-dist[E[e].b], E[e].b));
            }
        }
    }
    int v = N - 1;
    int res = dist[v];
    while (v) 
    {
        int e = par[v];
        E[e].cap--; 
        E[e ^ 1].cap++;
        v = E[e].a;
    }
    return res;
}

int main() 
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> B[i];
    for (int i = 0; i < n; i++) 
    {
        int j = 0;
        while (j < n)
            if (B[i][j] == '#') 
                j++;
            else 
            {
                id++;
                while (j < n && B[i][j] != '#') 
                {
                    R[i][j] = id; j++;
                }
            }
    }
    int rownum = id;
    for (int j = 0; j < n; j++)
    {
        int i = 0;
        while (i < n)
            if (B[i][j] == '#') 
                i++;
            else 
            {
                id++;
                while (i < n && B[i][j] != '#') 
                {
                    C[i][j] = id; i++;
                }
            }
    }
    N = id + 2;
    for (int i = 1; i <= rownum; i++)
        for (int j = 0; j < n; j++)
            addEdge(0, i, 1, j);
    for (int i = rownum + 1; i <= id; i++)
        for (int j = 0; j < n; j++)
            addEdge(i, N - 1, 1, j);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
        if (B[i][j] != '#')
            addEdge(R[i][j], C[i][j], 1, 0);
    int res = 0;
    while (k--) 
        res += getCost();
    cout << res << endl;
    return 0;
}
