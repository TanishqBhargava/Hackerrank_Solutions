#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    unsigned long long int n,m;
    cin>>n>>m;
    unsigned long long int jar[n];
    unsigned long long int sum=0;
    while(m--){
        unsigned long long int a,b,k;
        cin>>a>>b>>k; 
        sum+=(b-a+1)*k;
    }
    unsigned long long int avg=sum/n;
    cout<<avg<<endl;
    
    return 0;
}
