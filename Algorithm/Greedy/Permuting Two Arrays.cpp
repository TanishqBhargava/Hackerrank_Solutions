/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;

bool solve() 
{
    int N, K;
    cin >> N >> K;
    vector<int> a(N), b(N);
    for (int i = 0 ; i < N; ++i) 
        cin >> a[i];
    for (int i =0 ; i < N; ++i) 
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    for (int i = 0; i < N; ++i) 
        if (a[i] + b[i] < K) 
        return false;
    return true;
}

int main() 
{
    int t; 
    cin >> t;
    for (int i =0; i < t; ++i) 
        cout << (solve() ? "YES" : "NO") << endl;
}
