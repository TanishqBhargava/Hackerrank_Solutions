/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef pair <int, int> ii;
const int Inf = 1000000000;
const int Maxn = 1015;
int n, m, k, N, R[Maxn][Maxn], C[Maxn][Maxn], dist[Maxn], par[Maxn], res, placeid, place[Maxn];
map <string, int> M;
string my[Maxn];
vector <int> neigh[Maxn];

void addEdge(int a, int b, int cap, int cost)
{
    neigh[a].push_back(b); 
    neigh[b].push_back(a);
    R[a][b] = cap; 
    C[a][b] = cost; 
    C[b][a] = -cost;
}

bool getFlow(int &cost)
{
    fill(dist, dist + N, Inf); 
    dist[0] = 0;
    priority_queue <ii> Q; 
    Q.push(ii(-dist[0], 0));
    while (!Q.empty()) 
    {
        int v = Q.top().second, d = -Q.top().first; Q.pop();
        if (d != dist[v]) 
            continue;
        for (int i = 0; i < neigh[v].size(); i++) 
        {
            int u = neigh[v][i];
            if (R[v][u] > 0 && d + C[v][u] < dist[u]) 
            {
                dist[u] = d + C[v][u]; par[u] = v;
                Q.push(ii(-dist[u], u));
            }
        }
    }
    int v = N - 1; cost = dist[v];
    if (cost >= Inf) 
        return false;
    while (v) 
    {
        int u = par[v];
        R[u][v]--; 
        R[v][u]++;
        v = u;
    }
    return true;
}

int main() 
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) 
    {
        string nam; 
        int price; 
        cin >> nam >> price;
        M[nam] = price * 5;
    }
    N = 1 + n + 1 + n + 1;
    for (int i = 0; i < n; i++) 
    {
        cin >> my[i]; 
        int c = M[my[i]];
        addEdge(0, i + 1, 1, 0);
        addEdge(i + 1, n + 1, 1, c);
        for (int j = 0; j < i; j++)
            if (my[i] == my[j]) 
                addEdge(i + 1, n + j + 2, 1, c / 5 * 4);
            else 
                addEdge(i + 1, n + j + 2, 1, c);
        addEdge(n + i + 2, N - 1, 1, 0);
    }
    addEdge(n + 1, N - 1, m, 0);
    int add;
    while (getFlow(add)) 
        res += add;
    cout << setprecision(6) << ld(res) / 5.0l << endl;
    for (int i = 0; i < n; i++) 
    {
        int j = n + 1;
        while (R[j][i + 1] <= 0) 
            j++;
        int got = j - (n + 1);
        if (got == 0) 
            place[i] = ++placeid;
        else 
            place[i] = place[got - 1];
        cout << place[i] << endl;
    }
    return 0;
}
