#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )
int ri() 
{ 
  int x; 
  scanf("%d", &x); 
  return x; 
}

const int N = 1001, MOD = 1000000007; 
char a[N]; 
int binom[N][N], dp[N]; 
int pr[168], mu[N], np = 0; 
bool sieved[N];

void getPrimes() 
{ 
  mu[1] = 1; 
  for (int i = 2; i < N; i++) 
  { 
    if (! sieved[i]) 
    { 
      pr[np++] = i; 
      mu[i] = -1; 
    } 
    for (int j = 0; j < np && i*pr[j] < N; j++) 
    { 
      sieved[i*pr[j]] = true; 
      if (i%pr[j] == 0) 
      { 
        mu[i*pr[j]] = 0; 
        break; 
      } 
      mu[i*pr[j]] = - mu[i]; 
    } 
  } 
}

int main() 
{ 
  getPrimes(); 
  REP(i, N+1) 
  { 
    binom[i][0] = binom[i][i] = 1; 
    FOR(j, 1, i) binom[i][j] = (binom[i-1][j-1]+binom[i-1][j])%MOD; 
  } 
  for (int cc = ri(); cc--; ) 
  { 
    int n = ri(), k = ri(), ans = 0; 
    scanf("%s", a); 
    FOR(i, 2, n+1) if (n%i == 0 && mu[i]) 
    { 
    int m = n/i; 
    fill_n(dp, k+1, 0); 
    dp[0] = 1; 
    REP(j, m) 
    { 
      int x = 0; 
      for (int g = j; g < n; g += m) x += a[g] == '1'; 
      int y = i-x; 
      ROF(g, 0, k+1) 
      dp[g] = ((g < x ? 0 : dp[g-x]) + (g < y ? 0 : dp[g-y])) % MOD; 
    } 
    ll sum = 0; 
    REP(j, k+1) 
    sum = (sum+dp[j])%MOD; 
    ans = (ans+sum*mu[i])%MOD; 
  } 
  REP(i, k+1) 
  ans = (ans+binom[n][i])%MOD; 
  printf("%d\n", (ans+MOD)%MOD); 
  } 
}
