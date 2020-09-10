#include<bits/stdc++.h>
using namespace std;
int a, s, d[100002], f[100002], g, h, j, k, l, i, n, m;

int main()
{
    cin >> n >> k;
    for(i = 0; i < n; i++)
    {
        cin >> d[i];
        f[d[i]] = i;
    }
    for(i = n; i > 0; i--)
    {
        if(f[i]!=n-i) 
        {
            swap(d[f[i]],d[n-i]); 
            swap(f[i],f[d[f[i]]]);
            k--;
        }
        if(k == 0) 
            break;
    }
    for(i = 0; i < n; i++) 
        cout << d[i] << " ";
}
