#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N; cin >> N;
    long long len[N];
    for (int i=0;i<N;i++)
        cin >> len[i];
    sort(len,len+N,greater<long long>());
    for (int i=0; i+2<N;i++) 
    {
        if (len[i] < len[i+1]+len[i+2]) 
        {
            cout << len[i+2] << " " << len[i+1] << " " << len[i] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
