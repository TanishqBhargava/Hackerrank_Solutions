#include <bits/stdc++.h>
#define ll long long int
#define cases int testcase; cin >> testcase; while(testcase--)
using namespace std;
const int N = 1e3 + 2;
const int MOD = 1e9;
ll dp[N][N];

int main() {
    int n,k,t;
    for(int i=1; i<N; i++) {
        for(int j=1; j<N; j++) {
            if(i==1) {
                dp[i][j] = 1;
            } else if(j==1) {
                dp[i][j] = i;
            } else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
            }
        }
    }
    cases {
        cin >> n >> k;
        cout << dp[n][k] << endl;
    }
    return 0;
}
