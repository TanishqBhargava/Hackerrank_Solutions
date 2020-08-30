#include <bits/stdc++.h>

using namespace std;

const int p=1000000007;
int n, m, t;

long long fmod(long long N) {    if (N<2) return 1; else return (N*fmod(N-1))%p;    }
long long mmi(long long x)  {
    long long result=1, e=p-2;    
    while (e) {
        if (e & 1) result = (result*x)%p;
        x = (x*x)%p;
        e >>= 1;
    }
    return result;
}

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> m;
        printf("%lld\n", ((fmod(m+n-2)*mmi((fmod(m-1)*fmod(n-1))%p))%p));
    }
    return 0;
}
