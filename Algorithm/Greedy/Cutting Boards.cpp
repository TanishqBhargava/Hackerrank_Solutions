/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int t,m,n,x[1000000],y[1000000];

int main()
{
    long long int i, j, sum;
    cin >> t;
    while (t--)
    {
        sum = 0;
        cin >> m >> n;
        for (i = 0; i < m - 1; ++i) 
            cin >> x[i];
        for (i = 0; i < n - 1; ++i) 
            cin >> y[i];
        sort(x,x + m - 1,std::greater<long long int>());
        sort(y,y + n - 1,std::greater<long long int>());
        
        for (i = j = 0;(i < m - 1) && (j < n - 1);)
            if (x[i] > y[j]) 
                sum = (sum + x[i++] * (j + 1)) % 1000000007; 
            else 
                sum = (sum + y[j++] * (i + 1)) % 1000000007;
        for (;i < m - 1;++i) 
            sum = (sum + x[i] * n) % 1000000007;
        for (;j < n - 1;++j) 
            sum = (sum + y[j] * m) % 1000000007;
        cout << sum << endl;
    }
    return 0;
}
