#include <bits/stdc++.h>

using namespace std;
int main(){
    unsigned long long int n,count=0,x;
    cin>>n;
    while(n)
    {
        x=n&1ULL;
        if(x==0ULL)
         count++;   
        n>>=1;
    }
    cout<<(1ULL << count);
    return 0;
}
