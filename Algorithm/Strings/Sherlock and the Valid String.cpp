#include <bits/stdc++.h>

using namespace std;

char s[1234567];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  vector <int> cnt(26, 0);
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
  }
  for (int i = 0; i <= 26; i++) {
    if (cnt[i] == 0) {
      continue;
    }
    if (i < 26) {
      cnt[i]--;
    }
    vector <int> a = cnt;
    sort(a.begin(), a.end());
    int res = a[25];
    bool ok = true;
    for (int j = 0; j < 26; j++) {
      if (a[j] != 0 && a[j] != res) {
        ok = false;
        break;
      }
    }
    if (ok) {
      puts("YES");
      return 0;
    }
    if (i < 26) {
      cnt[i]++;
    }
  }
  puts("NO");
  return 0;
}
