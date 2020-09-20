#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
const int Maxn = 400005;
int n, k, q;
vector <ii> seq[Maxn], team[Maxn];

bool teamWin(int a, int b)
{
    int cura = team[a].size() - 1, curb = team[b].size() - 1;
    while (true) 
    {
        curb -= team[a][cura].first;
        if (curb < 0) return true;
        cura -= team[b][curb].first;
        if (cura < 0) return false;
        int hits = min((team[a][cura].second - 1) / team[b][curb].first + 1, 
                       (team[b][curb].second - 1) / team[a][cura].first);
        curb -= hits * team[a][cura].first;
        if (curb < 0) return true;
        cura -= hits * team[b][curb].first;
        if (cura < 0) return false;
    }
    return false;
}

int main() 
{
    cin >> n >> k >> q;
    for (int i = 0; i < n; i++) 
    {
        int s, t; 
        cin >> s >> t;
        seq[t].push_back(ii(s, i));
    }
    for (int i = 1; i <= k; i++) 
    {
        sort(seq[i].begin(), seq[i].end());
        for (int j = 0; j < seq[i].size(); j++)
            if (team[i].empty() || team[i].back().first != seq[i][j].first)
                team[i].push_back(ii(seq[i][j].first, 1));
            else team[i].push_back(ii(seq[i][j].first, team[i].back().second + 1));
    }
    for (int i = n; i < n + q; i++) 
    {
        int typ, x, y; 
        cin >> typ >> x >> y;
        if (typ == 1)
            if (team[y].empty() || team[y].back().first != x)
                team[y].push_back(ii(x, 1));
            else team[y].push_back(ii(x, team[y].back().second + 1));
        else printf("%d\n", teamWin(x, y)? x:y);
    }
    return 0;
}
