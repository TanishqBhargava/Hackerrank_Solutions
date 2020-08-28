#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

bool solve(const vector<unsigned>& a, list<unsigned>& states) {
    for (auto it = a.rbegin(), end = a.rend(); it != end; ) {
        auto n = states.front();
        if (n % *it == 0) {
            states.push_front(n /= *it);
            if (n == 1) return true;
            continue;
        }
        it++;
    }
    return false;
}

int main() {
    unsigned n, k;
    vector<unsigned> a;
    list<unsigned> result;

    cin >> n >> k;
    a.reserve(k);
    for (unsigned e; k-- > 0; ) {
        cin >> e;
        if (e <= n) a.push_back(e);
    }
    sort(a.begin(), a.end());

    result.push_back(n);

    if (solve(a, result))
        for (auto e : result) cout << e << " ";
    else cout << -1;
    cout << endl;

    return 0;
}
