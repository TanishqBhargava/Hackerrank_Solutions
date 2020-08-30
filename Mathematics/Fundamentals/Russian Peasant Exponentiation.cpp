#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<long, long> num;

long mod;

num operator* (num a, num b){
    long r = a.first * b.first - a.second * b.second;
    r %= mod;
    if (r < 0) r += mod;
    
    long i = a.second * b.first + a.first * b.second;
    i %= mod;
    if (i < 0) i += mod;
    
    return {r, i};
}

num raise(num z, long n){
    if (n == 1) return z;
    auto tmp = raise(z, n/2);
    if (n%2) return tmp * tmp * z;
    return tmp*tmp;
}

int main() {
    long q;
    cin >> q;
    while (q--){
        long a, b, k, m;
        cin >> a >> b >> k >> m;
        num z(a, b);
        mod = m;
        num r = raise(z, k);
        cout << r.first << ' ' << r.second << endl;
    }
    return 0;
}
