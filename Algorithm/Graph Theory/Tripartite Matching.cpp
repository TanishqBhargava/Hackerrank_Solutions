/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
int n, i, j, x, y;
vector <int> a[3][100005];
vector <pair<int, int> > b[3];
bool used[100005];

int main()
{
    cin >> n;
    for(i = 0; i < 3; i++)
    {
        int m;
        cin >> m;
        for(j = 0; j < m; j++)
        {
            int x, y;
            cin >> x >> y;
            a[i][x].push_back(y);
            a[i][y].push_back(x);
            b[i].push_back({x, y});
        }
    }
    long long ans = 0;
    for(i = 0; i < b[0].size(); i++)
    {
        int from = b[0][i].first;
        int to = b[0][i].second;
        for(j = 0; j < a[1][from].size(); j++)
            used[a[1][from][j]] = 1;
        for(j = 0; j < a[2][to].size(); j++)
            ans += used[a[2][to][j]];
        for(j = 0; j < a[1][from].size(); j++)
            used[a[1][from][j]] = 0;
        for(j = 0; j < a[2][from].size(); j++)
            used[a[2][from][j]] = 1;
        for(j = 0; j < a[1][to].size(); j++)
            ans += used[a[1][to][j]];
        for(j = 0; j < a[2][from].size(); j++)
            used[a[2][from][j]] = 0;
    }
    cout << ans << endl;
}
