/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, e;
        cin >> n >> e;
        vector<unordered_map<int,int> > mp(n + 1);
        for(int i = 0; i < e; i++)
        { 
            int e1,e2; 
            cin >> e1 >> e2;
            mp[e1][e2] = 1;
            mp[e2][e1] = 1;
        }
        int start;
        cin >> start ;
        queue<int> q;
        vector<int> dist(n + 1,INT_MAX);
        dist[start] = 0 ;
        unordered_set<int> unvisited;
        for(int i = 1; i <= n; i++)
            unvisited.insert(i) ;
        unvisited.erase(start);
        q.push(start);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            vector<int> toremove ;
            for(auto i:unvisited)
            {
                if(mp[node][i] != 1)
                {
                    dist[i] = dist[node]+1 ;
                    toremove.push_back(i);
                    q.push(i);
                }
            }
            for(auto i:toremove)
                unvisited.erase(i);
        }
        for(int i = 1; i <= n; i++) 
        {
            if(i != start)
                cout << dist[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
