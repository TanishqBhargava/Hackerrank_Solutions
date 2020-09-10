/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
int a, s, d[100002], f, g, h, j, k, l, i, n, m;

int main() 
{
    cin>>n>>m;
    f=0;
    l=-m+1;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        if(a) l=i;
        if(i-f>=m) 
        {
            f=l+m-1;
            k++;
        }
        if(i-f>=m) 
        {
            cout<<-1;
            return 0;
        }
    }
    if(f>=n)
        cout<<k; 
    else 
        cout<<k+1;
    return 0;
}
