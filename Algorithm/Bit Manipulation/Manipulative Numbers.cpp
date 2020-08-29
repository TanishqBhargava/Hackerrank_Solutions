#include <cstdio>
#include <map>
#include <utility>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define se second

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

const int N = 100;
int a[N];

int main()
{
  int n = ri();
  REP(i, n)
    a[i] = ri();
  int l = 0, h = 30;
  while (l < h) {
    map<int, int> c;
    int mi = l+h >> 1;
    REP(i, n)
      c[a[i] >> mi]++;
    bool major = false;
    for (auto x: c)
      if (x.se > n/2) {
        major = true;
        break;
      }
    if (! major)
      l = mi+1;
    else
      h = mi;
  }
  printf("%d\n", l-1);
}
