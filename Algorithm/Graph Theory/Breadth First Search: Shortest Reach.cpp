/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
int t, n, m, x, y, s;

int main(int argc, char const *argv[])
{
    cin >> t;
    for (int i = 0; i < t; i++) 
    {
        cin >> n >> m;
        vector<int> d (n+1, -1), g[1123];
        for (int j = 0; j < m; j++) 
        {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        cin >> s;
        queue< pair<int, int> > q;
        q.push(make_pair(s, 0));
        while (!q.empty()) 
        {
            pair<int, int> f = q.front();
            q.pop();
            int l = g[f.first].size();
            for (int j = 0; j < l; j++) 
            {
                if (d[g[f.first][j]] != -1) 
                    continue;
                else 
                {
                    d[g[f.first][j]] = f.second + 6;
                    q.push(make_pair(g[f.first][j], f.second + 6));
                }
            }
        }
        for (int j = 1; j <= n; j++)  
            if (j != s)
                cout << d[j] << " ";
        cout << endl;
    }
    return 0;
}
