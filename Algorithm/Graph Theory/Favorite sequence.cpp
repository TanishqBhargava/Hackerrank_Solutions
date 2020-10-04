/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6+10, maxM = 1e3+10;
int N, K, M, A[maxM], D[maxN], dd[maxN];
vector <int> E[maxN];
priority_queue <int, vector<int>, greater<int> > heap;

int main()
{
    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> K;
        for (int i = 1; i <= K; i++) 
        cin >> A[i], N = max(N,A[i]), dd[A[i]] = 1;
        for (int i = 2; i <= K; i++) D[A[i]]++, E[A[i - 1]].push_back(A[i]);
    }
    for (int i = 1; i <= N; i++)
    if (D[i] == 0 && dd[i]) 
        heap.push(i);
    while (! heap.empty())
    {
        int x = heap.top(); 
        heap.pop();
        cout << x << " ";
        for (int i = 0; i < E[x].size(); i++)
        {
            int t = E[x][i];
            D[t]--;
            if (D[t] == 0) 
                heap.push(t);
        }
    }
}
