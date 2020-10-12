/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
int const MOD = 998244353;
int const N   = 123456;
int const CO  = 1111;

void add(int &a, int b) 
{ 
    a += b; 
    if (a >= MOD) 
    a -= MOD; 
}

int  mul(int a, int b)  
{ 
    return (int) ((long long) a * b % MOD); 
}

int modpow(int a, int b) 
{
    int ret = 1;
    while (b > 0) 
    {
        if (b & 1) 
            ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}

int blockx[N / CO + 1][N], qx[N], cn, depth[N], vs[N], mvs[N], px[N], wx[N], tmp[N], ans[N], a[N], pr[N], n, m, k, h[N], was[N];
vector<int> edges[N], comps[N];

int dfs(int v, int root, int d) 
{
    vs[cn++] = v;
    depth[v] = d;
    int ret = 1;
    for (int to : edges[v]) 
    {
        if (to == root) 
            continue;
        ret = std::max(ret, dfs(to, root, d + 1) + 1);
    }
    mvs[v] = cn;
    return ret;
}

int G = 2, ROOT;
int const F = 19;
int rpws[(1 << F) + 1];
int INV[(1 << F) + 1];

int inverse(int x, int bits) 
{
    int y = 0;
    for (int i = 0; i < bits; i++) 
    { 
        y = (y << 1) | (x & 1); 
        x >>= 1; 
    }
    return y;
}

int zx[(1 << F) + 5], zy[(1 << F) + 5];

void fft(int *a, int bits, bool inv) 
{
    int n = 1 << bits;
    for (int i = 0; i < n; i++) 
    {
        int j = inverse(i, bits);
        if (i < j) 
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) 
    {
        int half = len >> 1;
        int step = (1 << F) / len;
        for (int i = 0; i < n; i += len) 
        {
            int k = inv ? (1 << F) : 0;
            for (int j = 0; j < half; j++) 
            {
                int u = a[i + j];
                int v = mul(a[i + j + half], rpws[k]);
                int x = u;
                add(x, v);
                int y = u;
                add(y, MOD - v);
                a[i + j] = x;
                a[i + j + half] = y;
                if (inv)
                    k -= step;
                else
                    k += step;
            }
        }
    }
    if (inv) 
    for (int i = 0; i < n; i++) 
    { 
        a[i] = mul(a[i], INV[n]); 
    }
}

void mul(int maxDepth, int size, int *p, int *q) 
{
    int bits = 0;
    while (1 << bits < 2 * (maxDepth + size)) 
        ++bits;
    int n = (1 << bits);
    memset(zx, 0, sizeof(zx[0]) * n);
    memset(zy, 0, sizeof(zy[0]) * n);
    for (int i = 0; i < maxDepth + size; i++) 
    { 
        zx[i] = p[i]; 
        zy[i] = q[i]; 
    }
    fft(zx, bits, false);
    fft(zy, bits, false);
    for (int i = 0; i < n; i++) 
    { 
        zx[i] = mul(zx[i], zy[i]); 
    }
    fft(zx, bits, true);
    memset(p, 0, sizeof(p[0]) * (maxDepth + size));
    for (int i = 0; i < n; i++)
        add(p[i < maxDepth ? i : (maxDepth + (i - maxDepth) % size)], zx[i]);
}

void mul3(int maxDepth, int size, int *p, int *q) 
{
    for (int i = 0; i < maxDepth + size; i++) 
        tmp[i] = 0;
    for (int i = 0; i < maxDepth + size; i++) 
    {
        for (int j = 0; j < maxDepth + size; j++) 
        {
            int k = (i + j);
            if (k >= maxDepth) 
                k = maxDepth + (k - maxDepth) % size;
            add(tmp[k], mul(p[i], q[j]));
        }
    }
    for (int i = 0; i < maxDepth + size; i++) 
        p[i] = tmp[i];
}

int main() 
{
    while (modpow(G, (MOD - 1) / 2) == 1) 
        ++G;
    int po = (MOD - 1) / (1 << F);
    ROOT = 1;
    for (int i = 0; i < po; i++) 
        ROOT = mul(ROOT, G);
    rpws[0] = 1;
    for (int i = 1; i <= 1 << F; i++) 
        rpws[i] = mul(ROOT, rpws[i - 1]);
    INV[1] = 1;
    for (int i = 2; i <= 1 << F; i++) 
        INV[i] = mul(MOD - MOD / i, INV[MOD % i]);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) 
    {
       cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < m; i++) 
        cin >> pr[i];
    for (int i = 0; i < n; i++) 
        edges[a[i]].push_back(i);
    int T = 0;
    for (int i = 0; i < n; i++) 
    {
        if (was[i]) 
            continue;
        int v = i;
        ++T;
        while (!was[v]) 
        { 
            was[v] = T; 
            v = a[v]; 
        }
        if (was[v] == T) 
        {
            int count = 1;
            for (int u = a[v]; u != v; u = a[u]) 
                ++count;
            comps[count].push_back(v);
        }
    }
    int const FIRST_PROB = modpow(n, MOD - 2);
    for (int size = 1; size <= n; size++) 
    {
        if (comps[size].empty()) 
            continue;
        auto &cc = comps[size];
        cn = 0;
        int maxDepth = 0;
        for (int v : cc) 
        {
            h[v] = dfs(v, v, 0);
            maxDepth = std::max(maxDepth, h[v]);
        }
        memset(px, 0, sizeof(px[0]) * (size + maxDepth));
        for (int i = 0; i < m; i++)
            add(px[i < maxDepth?i:(maxDepth+(i - maxDepth) % size)], pr[i]);
        memset(wx, 0, sizeof(wx[0]) * (size + maxDepth));
        wx[0] = 1;
        for (int d = k; d > 0; d >>= 1) 
        {
            if ((d & 1) == 1) 
                mul(maxDepth, size, wx, px);
            mul(maxDepth, size, px, px);
        }
        sort(cc.begin(), cc.end(), [](int i, int j) 
        { 
            return h[i] > h[j]; 
        });
        for (int root : cc) 
        {
            while (h[root] < maxDepth) 
            {
                add(wx[maxDepth - 1], wx[maxDepth - 1 + size]);
                wx[maxDepth - 1 + size] = 0;
                --maxDepth;
            }
            cn = 0;
            dfs(root, root, 0);
            memset(px, 0, sizeof(px[0]) * (size + maxDepth));
            for (int i = 0; i < cn; i++) 
            add(px[maxDepth - depth[vs[i]]-1], FIRST_PROB);
            mul(maxDepth, size, px, wx);
            for (int u = a[root], i = maxDepth; ; u = a[u], i++) 
            {
                add(ans[u], px[i]);
                if (u == root) 
                    break;
            }
            for (int i = 0; i < cn; i += CO) 
            {
                for (int j = 0; j < maxDepth; j++) 
                    px[j] = 0;
                int to = std::min(cn, i + CO);
                for (int j = i; j < to; j++) 
                {
                    int v = vs[j];
                    add(px[maxDepth - depth[v] - 1], FIRST_PROB);
                }
                mul(maxDepth, 1, px, wx);
                int bx = i / CO;
                for (int j = 0; j < maxDepth; j++) 
                    blockx[bx][j] = px[j];
            }
            for (int i = 0; i < cn; i++) 
            {
                int v = vs[i];
                int from = i;
                int to = mvs[v] - 1;
                int bleft = from / CO;
                int bright = to / CO;
                int z = 0;
                while (from <= to && from / CO == bleft) 
                {
                    int u = vs[from];
                    add(z, wx[depth[u] - depth[v]]);
                    ++from;
                }
                while (from <= to && to / CO == bright) 
                {
                    int u = vs[to];
                    add(z, wx[depth[u] - depth[v]]);
                    --to;
                }
                add(ans[v], mul(z, FIRST_PROB));
                while (from <= to) 
                {
                    add(ans[v], blockx[from / CO][maxDepth - depth[v] - 1]);
                    from += CO;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) 
        cout << ans[i] << endl;
}
