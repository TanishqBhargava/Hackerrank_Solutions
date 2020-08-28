#include<bits/stdc++.h>
using namespace std;

int main()
{
     int n ; cin>>n ;
     for(int k = 0 ;  k< n ; ++k)
     {
         
     string s1 ;
     cin>>s1 ;
     int i = 0  ;
     int j = s1.length() - 1 ;
     int ans = 0 ;
     while(i <= j )
      {
          int max1 = max((int)s1[i],(int)s1[j]) ;
          int min1 = min ((int)s1[i],(int)s1[j]) ;
          ans += (max1 - min1) ;
          i++;
          j--;
   
      }
      cout<<ans<<"\n" ;
     }
    return 0;
}
