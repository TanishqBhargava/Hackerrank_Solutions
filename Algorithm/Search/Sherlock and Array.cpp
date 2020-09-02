#include <bits/stdc++.h>
using namespace std;


int main() {
    int t,n;
    cin>>t;

    int i,q;
    for(q=1;q<=t;q++)
    { cin>>n; long long int j,s1=0,s2=0,l=0;
       long long int ar[n];
        for(i=0;i<n;i++)
        {cin>>ar[i];
         s2+=ar[i];
        } 
      for(i=0;i<n;i++)
      { if(i>=1)
          s1+=ar[i-1];
       s2=s2-ar[i];
       if(s1==s2)
           {l=1;
       break;}
      }
    if(l==1)
        cout<<"YES"<<endl;
     else if(l==0||n==1)
         cout<<"NO"<<endl;
    }

    return 0;
}
