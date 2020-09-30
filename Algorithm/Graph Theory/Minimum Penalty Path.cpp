/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include<bits/stdc++.h>
using namespace std;
int dist[1001][1234];
vector< pair< int , int  > > graph[1001];

void dfs(int node , int Or )
{
    dist[node][Or] = 1;
    for(int i = 0;  i < graph[node].size() ; ++i )
    {
        if(!dist[graph[node][i].first][Or|graph[node][i].second] )
            dfs(  graph[node][i].first ,  Or|graph[node][i].second );
    }
}

int main()
{
    cin.sync_with_stdio(false);
    int N , M;
    cin >> N >> M;
    while(M--)
    {
        int u , v , c;
        cin >> u >> v >> c;
        graph[u].push_back({ v , c});
        graph[v].push_back({ u , c});
    }
    int A , B;
    cin >> A >> B;
    dfs(A , 0 );
    int Ans = -1;
    for(int i = 1024 ; i >= 0 ; --i )
        if(dist[B][i])
            Ans = i;
            cout << Ans << endl;
    return 0;
}
