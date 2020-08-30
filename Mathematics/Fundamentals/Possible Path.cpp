#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
return b == 0 ? a : gcd(b, a % b);
}

int main() {

int t,i;
cin >> t;

for (i = 0;i<t;i++){

    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (gcd(abs(x1),abs(y1)) == gcd(abs(x2),abs(y2))){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}
}
