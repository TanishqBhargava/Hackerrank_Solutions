#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int s[1000];
const int N = 800;
const int MAXM = 100000;
int m;
int nxt[MAXM][10];
int cut[MAXM];
int w[MAXM], u[MAXM];
int state[1000][305];
char val[1000][305];
void build() {
  memset(nxt, -1, sizeof(nxt));
  memset(cut, -1, sizeof(cut));
  memset(state, -1, sizeof(state));
  m = 1;
  int n = 1; s[0] = 1;
  for(int i=0;i<=N;i++) {
    int pos = 0;
    for(int j=0;j<n;j++) {
      if(nxt[pos][s[j]] == -1) {
        nxt[pos][s[j]] = m++;
      }
      pos = nxt[pos][s[j]];
      state[i][j] = pos;
      val[i][j] = s[j];
    }
    for(int j=0;j<n;j++) s[j] *= 2;
    for(int j=0;j<n;j++) if(s[j]>=10) { s[j+1] += s[j]/10; s[j]%=10; }
    n += (s[n]>0);
  }
  cut[0] = 0;
  for(int j=0;j<n;j++) {
    for(int i=0;i<=N;i++) {
      int pos = state[i][j];
      if(pos == -1 || u[pos]) continue;
      u[pos] = 1;
      if(j==0) cut[pos] = 0;
      else {
        int k = cut[state[i][j-1]];
        while(k && nxt[k][val[i][j]] == -1) k = cut[k];
        cut[pos] = max(nxt[k][val[i][j]], 0);
      }
      w[pos] = w[cut[pos]] + (state[i][j+1] == -1);
    }
  }
}
char r[100005];
void solve() {
  scanf("%s", r);
  int L = strlen(r), pos = 0, ans = 0;
  reverse(r, r+L);
  for(int i=0;i<L;i++) {
    int t = r[i]-'0';
    while(pos && nxt[pos][t] == -1) pos = cut[pos];
    pos = max(0, nxt[pos][t]);
    ans += w[pos];
  }
  printf("%d\n", ans);
}
int main(void) {
  build();
  int T;
  scanf("%d", &T);
  while(T--) solve();
  return 0;
}
