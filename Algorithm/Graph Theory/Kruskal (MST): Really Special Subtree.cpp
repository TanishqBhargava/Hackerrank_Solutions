/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, w;
int p[3030];
pair<int, pair<int, int>> edge[5000000];

int find(int i) 
{ 
    return p[i] == i ? i : p[i] = find(p[i]); 
}

int main() 
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) 
        p[i] = i;
    for (int i = 0; i < m; ++i) 
    {
        cin >> a >> b >> w;
        edge[i] = make_pair(w, make_pair(a, b));
    }
    sort(edge, edge + m);
    int ans = 0;
    for (int i = 0; i < m; ++i) 
    {
        int x = find(edge[i].second.first);
        int y = find(edge[i].second.second);
        if (x != y) 
        {
            p[x] = y;
            ans += edge[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}
