/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
#define N 10
int n, m, now = 0, hor[N + 1][N + 1], ver[N + 1][N + 1];
map<int, int> h[2];
map<int, int> :: iterator it;

inline int get(int x, int p) 
{                
    return (x >> (p - 1 << 1) & 3);
}

inline int Set(int v, int p) 
{
    return (v << (p - 1 << 1));
}

inline void update(int x, int v) 
{
    h[now][x] = (h[now].find(x) == h[now].end()) ? v : min(h[now][x], v);
}

void decrypt(int x) 
{
    for (int i = 1; i <= m + 1; ++i, x >>= 2) 
    {
        int a = x & 3;
        if (a == 0)      
            cout << "#";
        else if (a == 1) 
            cout << "(";
        else if (a == 2) 
            cout << ")";
    }
}

int main() 
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < m; ++j)
            cin >> hor[i][j];
    for (int i = 1; i < n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> ver[i][j];
    int ans = INT_MAX;
    h[now][0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) 
        {
            now ^= 1;
            h[now].clear();
            for (it = h[now ^ 1].begin(); it != h[now ^ 1].end(); ++it) 
            {
                int x = it->first, v = it->second;
                if (j == 1) 
                    x <<= 2;
                int a = get(x, j), b = get(x, j + 1);
                if (a == 0 && b == 0) 
                {
                    if (i < n && j < m)
                        update(x + Set(1, j) + Set(2, j + 1), v);
                } 
                else if (a == 0 && b != 0) 
                {
                    if (j < m) 
                        update(x, v + ver[i - 1][j]);
                    if (i < n) 
                        update(x - Set(b, j + 1) + Set(b, j), v + ver[i - 1][j]);
                } 
                else if (a != 0 && b == 0) 
                {
                    if (i < n) 
                        update(x, v + hor[i][j - 1]);
                    if (j < m) 
                        update(x - Set(a, j) + Set(a, j + 1), v + hor[i][j - 1]);
                } 
                else if (a == 1 && b == 1) 
                {
                    int k = 0, p = j + 1, c;
                    while (k < 1) 
                    {
                        c = get(x, ++p);
                        if (c == 1) 
                            --k;
                        else if (c == 2) 
                            ++k;
                    }
                    update(x - Set(1, j) - Set(1, j + 1) - Set(1, p), v + hor[i][j - 1] + ver[i - 1][j]);
                } 
                else if (a == 2 && b == 2) 
                {
                    int k = 0, p = j, c;
                    while (k < 1) 
                    {
                        c = get(x, --p);
                        if (c == 1) 
                            ++k;
                        else if (c == 2) 
                            --k;
                    }
                    update(x - Set(2, j) - Set(2, j + 1) + Set(1, p), v + hor[i][j - 1] + ver[i - 1][j]);
                } 
                else if (a == 1 && b == 2) 
                {
                    if (i == n && j == m) 
                        ans = min(ans, v + hor[i][j - 1] + ver[i - 1][j]);
                } 
                else if (a == 2 && b == 1) 
                {
                    update(x - Set(2, j) - Set(1, j + 1), v + hor[i][j - 1] + ver[i - 1][j]);
                }
            }
        }
        cout << ((ans == INT_MAX) ? 0 : ans) << endl;   
        return 0;
}
