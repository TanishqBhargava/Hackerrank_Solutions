#include <bits/stdc++.h>

using namespace std;
int main() {
int T;
cin >> T;
int max=1000000;
for(int t=0 ; t<T ; t++){
    int l,b,n,temp;
    cin >> l >> b;

    for(int i=1 ; i<=l ; i++){
        if(l%i==0 && b%i==0){
            n=(l*b)/(i*i);
            if(n<max)
                max=n;
        }
    }
    cout << max << endl; 
    max=1000000;
} 
return 0;
}
