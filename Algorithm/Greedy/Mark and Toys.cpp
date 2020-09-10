/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n,M;
    cin >> n >> M;
    int ary[n];
    for(int i = 0; i < n; i++)
    cin >> ary[i];
    sort(ary, ary + n);
    int cnt = 0;
    for(int i = 0; i < n && M - ary[i] >= 0; i++)
    {
        M -= ary[i];
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
