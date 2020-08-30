#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define div 1000000007

using namespace std;

int com[2017][2017];

int main()
{
    int n,r,a,b,c;
    for(n=0; n<=2000; n++)
    {
        for(r=0; r<=n; r++)
        {
            if(r==0 || r==n)
                com[n][r]=1;
            else
                com[n][r]=(com[n-1][r-1]+com[n-1][r])%1000000007;
        }
    }
    cin>>c;
    while(c--)
    {
        cin>>a>>b;
        cout<<com[a+b-1][b-1]<<endl;
    }

    return 0;
}
