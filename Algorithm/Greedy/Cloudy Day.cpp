#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    vector<pair<int, int>> xp(n);
    for (auto &pi : xp)
        cin >> pi.second;
    for (auto &xi : xp)
        cin >> xi.first;
    cin >> m;
    vector<int> y(m);
    vector<int> r(m);
    for (auto &yi : y)
        cin >> yi;
    for (auto &ri : r)
        cin >> ri;

    vector<tuple<int, int>> cb;
    vector<tuple<int, int>> ce;
    for (int i = 0; i < m; i++) 
    {
        cb.emplace_back(y[i] - r[i], i);
        ce.emplace_back(y[i] + r[i], i);
    }
    sort(xp.begin(), xp.end());
    sort(cb.begin(), cb.end());
    sort(ce.begin(), ce.end());

    long init = 0;
    unordered_set<int> cls;
    vector<long> ps(m);
    for (uint i = 0, cbl = 0, cel = 0; i < n; i++) 
    {
        while (cbl < cb.size() && get<0>(cb[cbl]) <= xp[i].first) 
        {
            cls.insert(get<1>(cb[cbl]));
            cbl++;
        }
        while (cel < ce.size() && get<0>(ce[cel]) < xp[i].first) 
        {
            cls.erase(get<1>(ce[cel]));
            cel++;
        }
        if (cls.size() == 0) 
        {
            init += xp[i].second;
        } else if (cls.size() == 1) 
        {
            ps[*cls.begin()] += xp[i].second;
        }
    }
    cout << *max_element(ps.begin(), ps.end()) + init << endl;
    return 0;
}
