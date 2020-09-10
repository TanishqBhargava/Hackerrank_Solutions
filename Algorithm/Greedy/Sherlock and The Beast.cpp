#include <bits/stdc++.h>
using namespace std;
void solve() 
{
    int n;
    cin >> n;
    int a = n - n % 3;
    while(a > 0 && (n - a) % 5) 
        a -= 3;
    if(a >= 0 && (n - a) % 5 == 0) 
    {
        for(int i = 0; i < a; ++i) 
            cout << 5;
        for(int i = 0; i < n - a; ++i) 
            cout << 3;        
        cout << endl;
    }
    else 
        cout << -1 << endl;   
}

int main() 
{
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i) 
        solve();
}
