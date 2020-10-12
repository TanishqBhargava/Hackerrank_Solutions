/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include<bits/stdc++.h>
using namespace std;
int read_p, read_ca;

inline int read()
{
    read_p = 0;
    read_ca = getchar();
    while(read_ca < '0' | read_ca > '9') 
        read_ca = getchar();
    while(read_ca >= '0' && read_ca <= '9') 
        read_p = read_p * 10 + read_ca - 48, read_ca = getchar();
    return read_p;
}
queue <int> q;
int n, m, dis[1001], mmh = 0;

inline int bfs(int x)
{
    int mmh = 0, i, j, k;
    for (i = 0; i < n; i++) 
        dis[i] = 1e9;
        dis[x] = 0;
    q.push(x);
    while (!q.empty()) 
        for (mmh = dis[k = q.front()],q.pop(), i = 0; i < m; i++) 
            if (j = (k * m + i) % n, dis[j] > dis[k] + 1) 
                dis[j] = dis[k] + 1, q.push(j);
    return mmh;
}

int main()
{
    register int i,j;
    n = read();
    m = read();
    for (i = 0; i < n; i++) 
        mmh = max(mmh,bfs(i));
    cout << mmh << endl;
    for (i = 0; i < n; i++, puts(""))
        for (j = 0; j < m; j++) 
            cout << (i*m+j)%n << " ";
}
