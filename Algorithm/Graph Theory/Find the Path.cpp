/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<vector<int64_t>> G;
const int64_t INF = 1e11;

vector<vector<int64_t>> dijk(int r, int c, int L, int R) 
{
    set<pair<int64_t, pair<int, int>>> Q;
    vector<vector<int64_t>> D(N, vector<int64_t>(R-L+1, INF));
    Q.insert(make_pair(0, make_pair(r,c)));
    vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    while (!Q.empty()) 
    {
        auto curr = *Q.begin();
        Q.erase(Q.begin());
        int64_t d = curr.first;
        int r = curr.second.first, c = curr.second.second;
        if (d > D[r][c - L]) 
            continue;
        D[r][c - L] = d;
        for (auto dir : dirs) 
        {
            int cr = r + dir[0];
            int cc = c + dir[1];
            if (cr < 0 || cc < L || cr >= N || cc > R)
                continue;
            int64_t cd = d + G[cr][cc];
            if (cd < D[cr][cc - L]) 
            {
                Q.insert(make_pair(cd, make_pair(cr, cc)));
                D[cr][cc - L] = cd;
            }
        }
    }
    return D;
}
vector<vector<int>> Qs;
vector<int64_t> ans;
vector<unordered_map<int, pair<int, vector<vector<int64_t>>>>> SPs(7);

void div_and_conq(int l, int r, vector<int> Qis) 
{
    if (l > r)
        return;
    int mid = (r + l) / 2;
    for (int i = 0; i < N; ++i) 
    {
        SPs[i][mid] = make_pair(l, dijk(i, mid, l, r));
    }
    vector<int> Qls, Qrs;
    for (int i : Qis) 
    {
        if (Qs[i][1] < mid && Qs[i][3] < mid) 
            Qls.push_back(i);
        else if (Qs[i][1] > mid && Qs[i][3] > mid) 
            Qrs.push_back(i);
        else
        { 
            for (int j = 0; j < N; ++j) 
            {
                for (auto& kv : SPs[j]) 
                {
                    int mid = kv.first;
                    int upperl = kv.second.first;
                    auto& SP = kv.second.second;
                    int64_t d = SP[Qs[i][0]][Qs[i][1] - upperl] + SP[Qs[i][2]][Qs[i][3]- upperl] + G[j][mid];
                    ans[i] = min(ans[i], d);
                }
            }
        }
    }
    div_and_conq(l, mid - 1, Qls);
    div_and_conq(mid + 1, r, Qrs);
    for (int i = 0; i < N; ++i) 
    {
        SPs[i].erase(mid);
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin >> N >> M;
    G.assign(N, vector<int64_t>(M));
    for (auto &v : G) 
    {
        for (int64_t& i : v) 
        {
            cin >> i;
        }
    }
    int Q;
    cin >> Q;
    Qs.resize(Q);
    ans.assign(Q, INF);
    vector<int> Qis;
    for (int i = 0; i < Q; ++i) 
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        Qs[i] = {a, b, c, d};
        Qis.push_back(i);
    }
    div_and_conq(0, M - 1, Qis);
    for (int64_t i : ans) 
    {
        cout << i << endl;
    }
    return 0;
}
