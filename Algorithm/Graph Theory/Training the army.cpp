/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
const int MAXV = 450,INF = 987654321;
unordered_map<int,int> res[MAXV];
bool V[MAXV];
int mf, f, s, t;

int send(int s,int t,int minn) 
{
    V[s] = true;
    if (s == t) 
        return minn;
    for(auto i = res[s].begin();i != res[s].end(); ++i)
    {
        int v = i->first, c = i->second;
        if (!V[v] && c > 0) 
        {
            if (int sent = send(v, t, min(minn, c))) 
            {
                res[s][v] -= sent;
                res[v][s] += sent;
                return sent;
            }
        }
    }
    return 0;
}

int main()
{
    int N, T;
    cin >> N >> T;
    s = 0; 
    t = 2 * N + T + 1;
    for(int i = 1; i <= N; i++)
    {
        int ci; 
        cin >> ci;
        if(ci != 0) 
            res[s][i] = ci, res[i][s] = 0;
    }
    for(int i = 1; i <= N; i++)
        res[i][N + i] = INF, res[N + i][i] = INF;
    for(int i = 2 * N + 1; i <= 2 * N + T; i++)
    {
        int an, bn;
        cin >> an;
        for(int j = 0; j < an; j++)
        {
            int ai; 
            cin >> ai;
            res[i][ai] = 0; 
            res[ai][i] = 1;
        }
        cin >> bn;
        for(int j = 0; j < bn; j++)
        {
            int bi; 
            cin >> bi;
            res[i][N + bi] = 1; 
            res[N + bi][i] = 0;
        }
    }
    for(int i = N + 1; i <= 2 * N; i++)
        res[i][t] = 1, res[t][i] = 0;
    mf = 0;
    memset(V, false, sizeof V);
    while(f = send(s, t, INF))
    {
        mf += f;
        memset(V, false, sizeof V);
    }
    cout << mf << endl;
    return 0;
}
