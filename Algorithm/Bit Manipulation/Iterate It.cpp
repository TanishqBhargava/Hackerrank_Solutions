#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
#include <array>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

const double PI = acos(-1.0);

template<typename T> struct TPoint2D {
  T X, Y;
  TPoint2D() : X(), Y() {}
  TPoint2D(const T& x, const T& y) : X(x), Y(y) {}
  TPoint2D(const TPoint2D<T>& p) : X(p.X), Y(p.Y) {}
  TPoint2D& operator=(const TPoint2D<T>& p) { X = p.X; Y = p.Y; return *this; }
  T operator&(const TPoint2D<T>& p) const { return X * p.X + Y * p.Y; }
  T operator^(const TPoint2D<T>& p) const { return X * p.Y - Y * p.X; }
  TPoint2D conj() const { return TPoint2D(X, -Y); }
  TPoint2D<T> operator*(const TPoint2D<T>& p) const { return TPoint2D<T>(*this & p.conj(), -*this ^ p.conj()); }
  TPoint2D<T> operator*(const T& p) const { return TPoint2D<T>(p * X, p * Y); }
  TPoint2D<T> operator-(void) const { return TPoint2D(-X, -Y); }
  TPoint2D<T> operator+(const TPoint2D<T>& p) const { return TPoint2D(X + p.X, Y + p.Y); }
  TPoint2D<T> operator-(const TPoint2D<T>& p) const { return *this + (-p); }
  T norm() const { return X * X + Y * Y; }
};

typedef TPoint2D<double> base;

void fft (vector<base>& a, bool invert) {
  int n = (int) a.size();
  for (int i=1, j=0; i<n; ++i) {
    int bit = n >> 1;
    for (; j>=bit; bit>>=1)
      j -= bit;
    j += bit;
    if (i < j)
      swap (a[i], a[j]);
  }
  for (int len=2; len<=n; len<<=1) {
    double ang = 2*PI/len * (invert ? -1 : 1);
    base wlen (cos(ang), sin(ang));
    for (int i=0; i<n; i+=len) {
      base w (1, 0);
      for (int j=0; j<len/2; ++j) {
        base u = a[i+j], v = a[i+j+len/2] * w;
        a[i+j] = u + v;
        a[i+j+len/2] = u - v;
        if (j % 32 == 0) w = base(cos(ang*j), sin(ang*j));
        w = w*wlen;
      }
    }
  }
  if (invert)
    for (int i=0; i<n; ++i)
      a[i] = a[i] * (1.0 / n);
}

vector<base> x, y;
vi mul(const vi & a, const vi & b) {
  int n = 1;
  while (n < a.size() + b.size()) n *= 2;
  x.assign(n, base(0,0));
  y.assign(n, base(0,0));
  for (int i = 0; i < a.size(); ++i) x[i] = base(a[i], 0);
  for (int i = 0; i < b.size(); ++i) y[i] = base(b[i], 0);
  fft(x, 0);
  fft(y, 0);
  for (int i = 0; i < x.size(); ++i) x[i] = x[i] * y[i];
  fft(x, 1);
  vi res(a.size()+b.size());
  for (int i = 0; i < res.size(); ++i) res[i] = round(x[i].X);
  return res;
}

void out(const vi & v) {
  for (int x : v) cerr << x << ' ';
  cerr << endl;
}

int main() {
  int n;
  cin >> n;
  vi a(n), ra, prod;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int res = 0;
  vi was(50001);
  while (!a.empty()) {
    ++res;
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    for (int i = 1; i < a.size(); ++i) a[i] -= a[0];
    a[0] = 0;
    int d = a[0];
    for (int i = 1; i < a.size(); ++i) d = __gcd(d, a[i]);
    if (d > 1) for (int i = 1; i < a.size(); ++i) a[i] /= d;
    int N = a.back();
    if (a.size() == N + 1 || a[1] == 1 || a[a.size() - 2] == N-1) {
      res += N;
      break;
    }
    if (a.size()*(ll)a.size() <= 5*N) {
      ra.clear();
      for (int i = 0; i < a.size(); ++i) for (int j = i + 1; j < a.size(); ++j) {
        int d = a[j] - a[i];
        if (was[d] == res) continue;
        was[d] = res;
        ra.push_back(d);
      }
      a.swap(ra);
    } else {
      ra.assign(N + 1, 0);
      for (int x : a) ra[x] = 1;
      a = ra;
      reverse(ra.begin(), ra.end());
      prod = mul(a, ra);
      //out(a);
      a.clear();
      for (int i = 0; i < prod.size(); ++i) if (prod[i] && i != N) {
        a.push_back(abs(N - i));
      }
    }
  }
  cout << res << endl;
  return 0;
}
