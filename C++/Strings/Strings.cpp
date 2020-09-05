#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    cout << a.size() << ' ' << b.size() << endl << a + b << endl;
    swap(a[0] , b[0] );
    cout << a << ' ' << b;
    return 0;
} 
