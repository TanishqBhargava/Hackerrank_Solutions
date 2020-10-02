/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
#define maxn 4000010
bool prime[50000];
int pn,f[maxn],t[maxn],p[maxn],ii,fl[maxn],o[maxn],tot,n,L[maxn],d[maxn],q[maxn],q1,q2,u[maxn],it,vn,qq,ret,i,a[maxn],b[maxn],j,ai,upper,primes[10000];
map<int,int>ma;

void addedge(int x,int y)
{
    t[++ii] = y;p[ii] = f[x];f[x] = ii;fl[ii] = 1;o[ii] = ii + 1;
    t[++ii] = x;p[ii] = f[y];f[y] = ii;fl[ii] = 0;o[ii] = ii - 1;
}

int giveidx(int k)
{
    if(!ma[k])
        ma[k] = ++tot;
    return ma[k];
}

int dfs(int k,int carry)
{
    if(k == 2 + n + n)
        return carry;
    if(!carry)
        return 0;
    while(L[k])
    {
        if(d[t[L[k]]] == 1 + d[k] && fl[L[k]])
        {
            int pushed = dfs(t[L[k]],min(carry,fl[L[k]]));
            if(pushed)
            {
                fl[L[k]] -= pushed;
                fl[o[L[k]]] += pushed;
                L[k] = p[L[k]];            
                return pushed;
            }
            else 
                L[k] = p[L[k]];
        }
        else 
            L[k] = p[L[k]];
    }
    return 0;
}

bool bfs()
{
    q1 = q2 = 0;
    q[q1++] = 1;
    u[1] = ++it;
    while(q1 != q2)
    {
        vn = q[q2++];
        qq = f[vn];
        while(qq)
        {
            if(u[t[qq]] != it && fl[qq])
            {
                u[t[qq]] = it;
                d[t[qq]] = 1 + d[vn];
                q[q1++] = t[qq];
            }
            qq = p[qq];
        }
    }
    return u[2 + n + n] == it;
}

void Flow()
{
    while(1)
    {
        for(int i = 1; i <= tot; i++)
            L[i] = f[i];
        if(!bfs())
            return ;
        while(int nF = dfs(1, n + 2))
            ret += nF;
    }
}

int main (int argc, char * const argv[]) 
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    tot = 2 + n + n;
    for(i = 1; i <= n; i++)
        cin >> a[i];
    for(i = 1; i <= n; i++)
        cin >> b[i];
    for(i = 1; i <= n; i++)
        upper = max(upper, max(a[i], b[i]));
    upper = sqrt(upper) + 1;
    for(i = 2; i <= upper; i++)
        if(!prime[i])
        {
            primes[++pn] = i;
            for(j = i * i; j <= upper; j += i)
                prime[j] = 1;
        }
    primes[pn + 1] = 1000000001;
    for(i = 1; i <= n; i++)
    {
        addedge(1, 1 + i);
        ai = a[i];
        int lim = sqrt(a[i]);        
        for(j = 1; primes[j] <= lim && (primes[j] * primes[j]) <= ai; j++)
        if(ai % primes[j] == 0)
        {
            addedge(1 + i, giveidx(primes[j]));
            while(ai % primes[j] == 0)
                ai /= primes[j];
        }
        if(ai>1)
            addedge(1 + i, giveidx(ai));        
    }
    for(i = 1; i <= n; i++)
    {
        addedge(1 + n + i, 2 + n + n);
        ai = b[i];
        int lim = sqrt(b[i]);
        for(j = 1; primes[j] <= lim && (primes[j] * primes[j]) <= ai; j++)
        if(ai % primes[j] == 0)
        {
            if(ma[primes[j]])
                addedge(ma[primes[j]], 1 + n + i);
            while(ai % primes[j] == 0)
                ai /= primes[j];
        }
        if(ma[ai])
            addedge(ma[ai], 1 + n + i);
    }
    Flow();
    cout << ret << endl;
    return 0;
}
