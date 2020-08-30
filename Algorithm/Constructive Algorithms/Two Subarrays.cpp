#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <complex>
#include <cstring>
#include <cassert>
#include <bitset>

using namespace std;
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repd(i, a, b) for(int i = (a); i > (b); i--)
#define forIt(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define forRev(it, a) for(__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
#define ft(a) __typeof((a).begin())
#define ll long long
#define ld long double
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define bitcount(n) __builtin_popcountll(n)
#define randchar() ((rand() % 26) + 'a')


typedef complex<ld> cplex;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int N = 200000 + 7;
const int M = 10007;
const int inf = 1e9 + 7;
const long long linf = 1ll * inf * (inf - 1);
const double pi = acos(-1);
const double eps = 1e-7;
const bool multipleTest = 0;


int mx;
int n;
int a[N];
int sum[N];
int RMQ[N][20];
int last[N][41];
int prv[41];

int curMx[N];
int possVal[N];

int LOG2[N];

int getMin(int u, int v) {
    int k = LOG2[v - u + 1];
    int lp = RMQ[u][k];
    int rp = RMQ[v - (1 << k) + 1][k];
    
    if (sum[lp] < sum[rp]) return lp;
    else return rp;
}

void solve() {
//    LOG2[1] = 0;
    for(int j = 2; j < N; ++j) {
        LOG2[j] = LOG2[j - 1];
        if (bitcount(j) == 1) LOG2[j] ++;
    }
    
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        RMQ[i][0] = i;
        sum[i] = sum[i - 1] + a[i];
        mx = max(mx, a[i]);
    }
    
    if (mx == 0) {
        cout << 0 << ' ' << n << '\n';
        return;
    }
    
    rep(j, 1, 20) {
        int lt = (1 << j);
        int half = lt >> 1;
        
        for(int i = 0; i + lt - 1 <= n; ++i) {
            int lp = RMQ[i][j - 1];
            int rp = RMQ[i + half][j - 1];
            if (sum[lp] < sum[rp]) RMQ[i][j] = lp;
            else RMQ[i][j] = rp;
        }
    }
    
    
    
    int ff = 0, mLen = 0, cnt = n;
    
    for(int i = 1; i <= n + 1; ++i) {
        rep(j, 1, mx + 1) last[i][j] = prv[j];
        if (a[i] > 0) prv[a[i]] = i;
    }
    
    for(int i = 1; i <= n; ++i) {
        
        if (sum[i] - sum[getMin(0, i - 1)] <= ff) continue;
        
        for(int j = 1; j <= mx + 1; ++j) curMx[j] = 0;
        int t = i + 1;
        
        int curInc = 0;
        
        do{
            
            
            int nxtPoint = 0;
            int topMax = 0;
            for(int j = mx; j > 0; --j) {
                if (last[t][j] > 0 && j + topMax > curMx[j]) {
                    nxtPoint = max(nxtPoint, last[t][j]);
                    possVal[j] = j + topMax;
                }
                topMax = max(topMax, curMx[j]);
            }
            
            if (nxtPoint < i) {
                int mnPoint = getMin(nxtPoint, t - 1);
                int cur = sum[i] - sum[mnPoint] - curInc;
                
                if (cur > ff) {
                    ff = cur;
                    mLen = i - mnPoint;
                    cnt = 1;
                } else {
                    if (cur == ff) {
                        if (mLen > i - mnPoint) {
                            mLen = i - mnPoint;
                            cnt = 1;
                        }
                        else if (mLen == i - mnPoint) ++cnt;

                    }
                }
            }
            
            
            if (nxtPoint) {
                int idx = a[nxtPoint];
                curMx[idx] = possVal[idx];
                curInc = max(curInc, curMx[idx]);
            }
            
            t = nxtPoint;
        }while (t > 0);
    }
    
    
    if (ff == 0) cnt = n;
    cout << ff << ' ' << cnt << '\n';
    
}


void test() {
    freopen("in.txt", "w", stdout);
    for(int i = 0; i < 50000; ++i) {
        printf("%c", randchar());
    }
    
    cout << '\n' << 100000 << '\n';
    
    rep(i, 0, 100000) {
        rep(t, 0, (rand() % 4) + 1) printf("%c", randchar());
        printf(" ");
        rep(t, 0, (rand() % 4) + 1) printf("%c", randchar());
        printf("\n");
    }
    
}


int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin);
#endif
    //    freopen("out.txt", "w", stdout);
    
    
    
    int Test = 1;
    if (multipleTest) {
        cin >> Test;
    }
    for(int i = 0; i < Test; ++i) {
        //        printf("Case #%d: ", i + 1);
        
        solve();
    }
    
#ifdef _LOCAL_
    cout<<"\n" << 1.0 * clock() / CLOCKS_PER_SEC<<endl;
#endif
}
