#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int _n=(n), i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << endl;

typedef long long LL; typedef unsigned long long ULL;
const int INF = 1000000000; const LL INFLL = LL(INF) * LL(INF);
template<class T> inline int size(const T&c) { return c.size(); }
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }

const int P1 = 1000000007;
const int P2 = 1000000009;
const int M1 = 786083483;
const int M2 = 878868465;

vector<int> powersM1;
vector<int> powersM2;

void ComputePowers(vector<int> &powers, int M, int P) {
  int pp = 1;
  REP(i,2000) {
    powers.push_back(pp);
    pp = LL(pp) * M % P;
  }
}

struct Hash {
  int len;
  int h1;
  int h2;
  Hash():len(0),h1(0),h2(0) {}
  void Append(char c) {
    ++len;
    h1 = (LL(M1) * h1 + (c-'a'))%P1;
    h2 = (LL(M2) * h2 + (c-'a'))%P2;
  }
  void Append(const Hash &h) {
    len += h.len;
    h1 = (LL(powersM1[h.len]) * h1 + h.h1) % P1;
    h2 = (LL(powersM2[h.len]) * h2 + h.h2) % P2;
  }
};

inline bool operator<(const Hash &a, const Hash &b) {
  if(a.h1 != b.h1) return a.h1 < b.h1;
  return a.h2 < b.h2;
}

inline bool operator==(const Hash &a, const Hash &b) {
  return a.h1 == b.h1 && a.h2 == b.h2;
}

int main() {
  ComputePowers(powersM1,M1,P1);
  ComputePowers(powersM2,M2,P2);

  int ntc; cin >> ntc;
  REP(tc,ntc) {
    int N; cin >> N;
    string text1,text2;
    cin >> text1 >> text2;

    vector<Hash> A(N+1),B(N+1),C(N+1),D(N+1);
    FOR(i,1,N) {
      A[i].Append(text1[i-1]);
      A[i].Append(A[i-1]);
      A[i].Append(text2[i-1]);

      B[i].Append(text2[i-1]);
      B[i].Append(B[i-1]);
      B[i].Append(text1[i-1]);
    }

    FORD(i,N-1,0) {
      C[i].Append(text1[i]);
      C[i].Append(C[i+1]);
      C[i].Append(text2[i]);

      D[i].Append(text2[i]);
      D[i].Append(D[i+1]);
      D[i].Append(text1[i]);
    }

    vector<Hash> allHashes;

    FOR(x0,0,N) REP(y0,2) {
      Hash h;
      if(y0==0) h.Append(B[x0]); else h.Append(A[x0]);
      int x=x0;
      int y=y0;
      for(;;) {
        Hash hF = h;
        if(y==0) hF.Append(C[x]); else hF.Append(D[x]);
        allHashes.push_back(hF);

        if(x==N) break;

        if(y==0) {
          h.Append(text1[x]);
          h.Append(text2[x]);
          y=1;
        } else {
          h.Append(text2[x]);
          h.Append(text1[x]);
          y=0;
        }
        ++x;
      }
    }

    FOR(x0,0,N) REP(y0,2) {
      Hash h;
      if(y0==0) h.Append(D[x0]); else h.Append(C[x0]);
      int x=x0;
      int y=y0;
      for(;;) {
        Hash hF = h;
        if(y==0) hF.Append(A[x]); else hF.Append(B[x]);
        allHashes.push_back(hF);

        if(x==0) break;

        --x;
        if(y==0) {
          h.Append(text1[x]);   
          h.Append(text2[x]);
          y=1;
        } else {
          h.Append(text2[x]);
          h.Append(text1[x]);
          y=0;
        }
      }
    }

    sort(allHashes.begin(), allHashes.end());
    int res = unique(allHashes.begin(), allHashes.end()) - allHashes.begin();
    cout << res << "\n";
  }
}
