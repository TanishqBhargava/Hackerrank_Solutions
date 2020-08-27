#include <bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        
        int temp = k;
        
        if(k == 0){
            for(int i = 1; i <= n; i++){
                cout << i << " ";
            }
        }else if((n % (2*k)) == 0){
            for(int i = 1; i <= n; i++){
                cout << i + temp << " ";
                if(i % k == 0){
                    temp = temp * -1;
                }
            }        
        }else{
            cout << -1;
        }
        
        cout << endl;
    }
    return 0;
}
