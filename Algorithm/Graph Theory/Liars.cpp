/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include<bits/stdc++.h>>
using namespace std;
const int Maxn = 105;
int dist[Maxn][Maxn];

int main(void)
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            dist[i][j] = j - i, dist[j][i] = 0;
    int A[M], B[M], C[M];
    for(int i = 0; i < M; i++)
    {
        cin >> A[i] >> B[i] >> C[i];
        dist[A[i] - 1][B[i]] = min(dist[A[i] - 1][B[i]], C[i]);
        dist[B[i]][A[i] - 1] = min(dist[B[i]][A[i] - 1], -C[i]);
    }
    for (int k = 0; k <= N; k++)
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    cout << -dist[N][0] << " " << dist[0][N] << endl;
    return 0;
}
