#include <bits/stdc++.h>

using namespace std;

unsigned long long int solve(unsigned long long int n, unsigned long long int m){
    // Complete this function
    unsigned long long int row = n;
    unsigned long long int column = m;
     unsigned long long int count = (((row-1)*column)+(column-1));
    return count;
}

int main() {
    unsigned long long int n;
    unsigned long long int m;
    cin >> n >> m;
    unsigned long long int result = solve(n, m);
    cout << result << endl;
    return 0;
}
