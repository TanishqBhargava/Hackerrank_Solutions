#include <bits/stdc++.h>
using namespace std;

template<class T>
struct Dictionary {
    vector<T> dat;

    Dictionary(vector<T> &d) : dat(d) {
        sort(dat.begin(), dat.end());
        dat.erase(unique(dat.begin(), dat.end()), dat.end());
    }

    int operator[](T v) {
        return lower_bound(dat.begin(), dat.end(), v) - dat.begin();
    }
};

int n;
int ans[1 << 19];
set<int> val[30];
int cnt = 0;

void dfs(int k, int d, int e, int up) {
    auto it = val[d].upper_bound(up);
    if (it == val[d].end()) return;

    if (k >= n - 1) {
        ans[k] = *it;
        val[d].erase(it);
        cnt++;
        return;
    }

    dfs(k * 2 + 1, d, e - 1, up);
    dfs(k * 2 + 2, e - 1, e - 1, *it);

    ans[k] = min(ans[k * 2 + 1], ans[k * 2 + 2]);
}

bool solve() {
    cin >> n;

    vector<int> a(n * 2 - 1);
    for (int i = 0; i < a.size(); i++) scanf("%d", &a[i]);
    vector<int> tmp(a);

    Dictionary<int> dict(a);
    if (dict.dat.size() != n) return false;
    for (int i = 0; i < a.size(); i++) a[i] = dict[a[i]];

    vector<int> freq(n);
    for (int x : a) freq[x]++;

    for (int i = 0; i < n; i++) if (freq[i] >= 30) return false;

    for (int i = 0; i < n; i++) {
        val[freq[i]].insert(i);
    }

    dfs(0, (int)log2(n) + 1, (int)log2(n) + 1, -1e9);

    if (cnt != n) return false;

    for (int i = 0; i < n * 2 - 1; i++) {
        ans[i] = dict.dat[ans[i]];
    }

    vector<int> check_a(ans, ans + n * 2 - 1);
    sort(check_a.begin(), check_a.end());
    sort(tmp.begin(), tmp.end());

    if (check_a != tmp) return false;

    return true;
}

int main() {
    if (solve()) {
        cout << "YES" << endl;

        for (int i = 0; i < n * 2 - 1; i++) {
            printf("%d ", ans[i]);
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}
