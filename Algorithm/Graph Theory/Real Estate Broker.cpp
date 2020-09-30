/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > houses(m);
    vector<pair<int, int> > clients(n);
    for (int i = 0; i < n; ++i)
        cin >> clients[i].first >> clients[i].second;
    for (int i = 0; i < m; ++i)
        cin >> houses[i].second >> houses[i].first;
    sort(clients.begin(), clients.end());
    sort(houses.begin(), houses.end());
    vector<int> sold(m);
    int cnt = 0;
    for (int cl = n-1; cl >= 0; --cl)
    {
        for (int hs = m - 1; hs >= 0; --hs)
        {
            if (sold[hs] == 0 && houses[hs].second > clients[cl].first && houses[hs].first <= clients[cl].second)
            {
                sold[hs] = 1;
                ++cnt;
                break;
            }
        }
    }
    cout<<cnt<<endl;
}
