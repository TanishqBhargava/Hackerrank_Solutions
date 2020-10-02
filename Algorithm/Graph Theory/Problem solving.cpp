/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
int t, n, v[300], k, match[300], visited[300];

bool dfs(int s) 
{
    if(visited[s]) 
        return false;
    visited[s] = true;
    for(int i = s + 1; i < n; i ++)
        if(abs(v[i] - v[s]) >= k)
            if(match[i] == -1 || dfs(match[i])) 
            {
                match[i] = s;
                return true;
            }
    return false;
}

int main() 
{
    for(cin >> t; t--; ) 
    {
        cin >> n >> k;
        for(int i = 0; i < n; i ++) 
            cin >> v[i];
        memset(match, -1, sizeof match);
        int result = n;
        for(int i = 0; i < n; i ++) 
        {
            memset(visited, 0, sizeof visited);
            if(dfs(i)) 
                result -= 1;
        }
        cout << result << endl;
    }
    return 0;
}
