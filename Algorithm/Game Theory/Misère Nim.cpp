#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
    int t;cin>>t;
      
    while(t--){int n;cin>>n;int m=n;long ans=0;int c=0;
               while(n--){long s;
                          cin>>s;
                          
                   ans^=s;
                          if(s==1) c++;
               }
        if((c!=m&&ans==0)||(c==m&&c%2!=0)) cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
    return 0;
}
