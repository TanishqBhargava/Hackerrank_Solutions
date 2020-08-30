#include <iostream>
#include <numeric>
#include <type_traits>
using namespace std;

#define FOR(i, a, b) for (remove_cv<remove_reference<decltype(b)>::type>::type i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define REP1(i, n) for (remove_cv<remove_reference<decltype(n)>::type>::type i = 1; i <= (n); i++)

const long N = 600, MOD = 1000000007;
int nim[N+1], mx[N+1], mex[N], s[2][N+1][N];

int main()
{
  long m, n, x;
  cin >> n >> m >> x;
  if (x == 2)
    FOR(i, 2, n+1)
      nim[i] = (i & 1) ^ 1;
  else if (x == 3) {
    long tick = 0, t;
    FOR(i, 2, n+1) {
      tick++;
      FOR(j, 1, i)
        if ((t = nim[j] ^ nim[i-j]) < i)
          mex[t] = tick;
      FOR(j, 1, i)
        FOR(k, 1, i-j)
          if ((t = nim[j] ^ nim[k] ^ nim[i-j-k]) < i)
            mex[t] = tick;
      while (mex[nim[i]] == tick)
        nim[i]++;
    }
  } else
    FOR(i, 2, n+1)
      nim[i] = i-1;
  FOR(i, 2, n+1) {
    mx[i] = 0;
    REP1(j, i)
      mx[i] = max(mx[i], mx[i-j] ^ nim[j]);
  }

  s[0][0][0] = 1;
  REP(i, m) {
    REP(j, n+1)
      fill_n(s[i+1&1][j], N, 0);
    REP(j, n)
      REP(k, mx[j]+1)
        if (s[i&1][j][k])
          REP1(jj, n-j) {
            long kk = k ^ nim[jj];
            if (kk < N) {
              int& t = s[i+1&1][j+jj][kk];
              t += s[i&1][j][k];
              if (t >= MOD)
                t -= MOD;
            }
          }
  }
  cout << accumulate(s[m&1][n]+1, s[m&1][n]+N, 0L) % MOD << endl;
}
