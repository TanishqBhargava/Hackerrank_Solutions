/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;

int main()
{  
    int n;
    cin >> n;
    map<string, int>mp;
    while (n--)
    {
        string t;
        cin >> t;
        mp[t]++;
    }
    int a;
    cin >> a;
    while (a--)
    {
        string t;
        cin >> t;
        cout << mp[t] << endl;
    }
    return 0;
}
