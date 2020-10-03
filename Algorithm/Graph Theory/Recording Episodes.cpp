/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 105;
const int Maxd = 4;
int q, n, s[Maxn][Maxd], col[Maxn], scol[Maxn], from;
bool tk[Maxn];

bool Intersect(int a, int b, int c, int d)
{
    return !(b < c || d < a);
}

bool Solve(int v, int to, int c)
{
    if (tk[v]) 
        return false;
    tk[v] = true;
    col[v] = c;
    for (int i = from; i <= to; i++) 
    if (v != i)
        if (Intersect(s[v][2 * c], s[v][2 * c + 1], s[i][2 * col[i]], s[i][2 * col[i] + 1]))
            if (!Solve(i, to, 1 - col[i])) 
                return false;
    tk[v] = false;
    return true;
}

int main() 
{
    cin >> q;
    while (q--) 
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < Maxd; j++)
                cin >> s[i][j];
        int best = -1, bl, br;
        for (from = 1; from <= n; from++) 
        {
            int i;
            for (i = from; i <= n; i++) 
            {
                tk[i] = false;
                for (int j = from; j < i; j++)
                    scol[j] = col[j];
                if (!Solve(i, i, 0)) 
                {
                    for (int j = from; j <= i; j++) 
                    {
                        col[j] = scol[j]; 
                        tk[j] = false;
                    }
                    if (!Solve(i, i, 1)) 
                        break;
                }
            }
            int cand = i - 1 - from;
            if (cand > best) 
            { 
                best = cand; 
                bl = from; 
                br = i - 1; 
            } 
        }
        cout << bl << " " << br << endl;
    }
    return 0;
}
