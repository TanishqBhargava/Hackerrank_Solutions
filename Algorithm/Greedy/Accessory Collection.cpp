#include<bits/stdc++.h>
using namespace std;
int T, L, A, N, D;

int main() 
{
    for(cin >> T; T--;) 
    {
        cin >> L >> A >> N >> D;
        if(D == 1) 
        {
            cout << 1LL * A * L << endl;
            continue;
        }
        long long ans = 0LL;
        for(int sec = 1; sec * (D - 2) < N; sec++) 
        {
            int f = N - sec * (D - 2) - 1;
            if(f < sec) break;
            if(1LL * f + 1LL * sec * (A - 1) < L) continue;
            long long ta = 1LL * f * A;
            int tmp = (L - f) / sec;
            ta += 1LL * (A - tmp + A - 1) * tmp / 2 * sec;
            int rem = L - f - tmp * sec;
            ta += 1LL * rem *(A - tmp - 1);
            ans = max(ans, ta);
        }
        if(!ans) 
            cout << "SAD" << endl;
        else 
            cout << ans << endl;
    }
    return 0;
}
