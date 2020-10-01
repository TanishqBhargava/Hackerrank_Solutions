/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
#define N 100100
vector <int> m[N];
int u[N], v[N], c;

void dfs(int i)
{
    u[i]=1;
    c++;
    for(int j=0; j<m[i].size(); j++)
        if(!u[m[i][j]]) 
            dfs(m[i][j]);
}

int main()
{
    int q;
    cin >> q;
    for(; q--; )
    {
        int n, k, l, i, j;
        cin >> n >> k;
        for(i = 0; i < n; u[i] = 0, m[i].clear(), i++);
        for(l = 0; l < k; cin >> i >>j, i--, j--, m[i].push_back(j), m[j].push_back(i), l++);
        j=0;
        for(i = 0; i < n; i++)
            if(!u[i]) 
            { 
                c = 0; 
                dfs(i); 
                v[j++] = c; 
            }
        sort(v, v + j);
        long long r = 0, s = 0;
        for(; j--; )
            for(l = 1; l < v[j]; s += 2 * l, r += s, k--, l++);
        r += k * s;
        cout << r << endl;
    }
    return 0;
}
