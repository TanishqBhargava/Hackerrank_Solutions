#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++)
    {
       cin >> a[a_i];
    }
    sort(a.begin(), a.end());
    int mn = 2000000005;
    for (int i = 0; i < a.size() - 1; i++) 
    {
        mn = min(mn, abs(a[i] - a[i + 1]));
    }
    cout << mn << endl;
    return 0;
}
