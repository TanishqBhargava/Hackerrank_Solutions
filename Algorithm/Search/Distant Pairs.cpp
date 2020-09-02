#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 200200;
bool bad[maxn];
vector<pair<int, int>> v;
int n, l;

const int base = 1 << 20;
namespace tree {

int t[base * 2];

void build() {
    forn (i, 2 * base)
        t[i] = -1;
}

void put(int pos, int val) {
    int v = pos + base;
    t[v] = val;
    while (v > 1) {
        v /= 2;
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
}

int get(int l, int r, int v = 1, int cl = 0, int cr = base) {
    if (l >= r)
        return -1;
    if (l <= cl && cr <= r)
        return t[v];
    if (r <= cl || cr <= l)
        return -1;
    int cc = (cl + cr) / 2;
    return max(get(l, r, v * 2, cl, cc), get(l, r, v * 2 + 1, cc, cr));
}

} 

bool check(int r) {
    forn (i, n) {
        int d = v[i].second - v[i].first;
        bad[i] = min(d, l - d) < r;
    }
    tree::build();
    vector<int> q;
    int ptr = 0;
    forn (i, n) {
        while (v[ptr].first <= v[i].first - r) {
            if (!bad[ptr]) {
                tree::put(v[ptr].second, v[ptr].first);
            }
            ++ptr;
        }
        if (bad[i])
            continue;
        int a = v[i].first, b = v[i].second;
        int mx = tree::get(max(0, b + r - l), a - r + 1);
        mx = max(mx, tree::get(a + r, b - r + 1));
        mx = max(mx, tree::get(b + r, min(l, a - r + l + 1)));
        if (mx == -1)
            continue;
        assert(mx + r <= v[i].first);
        if (mx + l >= b + r)
            return true;
    }
    return false;
}

int main() {
    #ifdef LOCAL
    assert(freopen("test.in", "r", stdin));
    #endif
    cin >> n >> l;
    forn (i, n) {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        v.emplace_back(a, b);
    }
    sort(v.begin(), v.end());
    int L = 0, R = l;
    while (L + 1 < R) {
        int C = (L + R) / 2;
        if (check(C))
            L = C;
        else
            R = C;
    }
    cout << L << '\n';
}
