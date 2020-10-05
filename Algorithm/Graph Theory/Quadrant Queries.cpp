/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
char flips[1 << 18] = {0};
int cnt[1 << 18][4] = {{0}};

void inc(int b, int v, int p = 1, int s = 0, int w = 1 << 17) 
{
    ++cnt[p][v];
    if ((w >>= 1) > 0) 
    {
        if (b < (s + w))
            inc(b, v, p << 1, s, w);
        else
            inc(b, v, (p << 1) + 1, s + w, w);
    }
}

void update(int b, int e, int o, int p = 1, int s = 0, int w = 1 << 17) 
{
    if (b <= s && e >= (s + w)) 
    {
        flips[p] ^= o;
        if (1 == o)
            swap(cnt[p][0], cnt[p][1]), swap(cnt[p][2], cnt[p][3]);
        else
            swap(cnt[p][0], cnt[p][2]), swap(cnt[p][1], cnt[p][3]);
    }
    else if (w > 1) 
    {
        int w1 = w >> 1;
        if (b < s + w1)
            update(b, e, o, p << 1, s, w1);
        if (e > s + w1)
            update(b, e, o, (p << 1) + 1, s + w1, w1);
        for (int i = 0; i < 4; ++i)
            cnt[p][i ^ flips[p]] = cnt[p << 1][i] + cnt[(p << 1) + 1][i];
    }
}

void query(int b, int e, int* v, int o = 0, int p = 1, int s = 0, int w = 1 << 17) 
{
    if (b <= s && e >= (s + w)) 
    {
        for (int i = 0; i < 4; ++i)
            v[i ^ o] += cnt[p][i];
    }
    else if ((w >>= 1) > 0) 
    {
        if (b < s + w)
            query(b, e, v, o ^ flips[p], p << 1, s, w);
        if (e > s + w)
            query(b, e, v, o ^ flips[p], (p << 1) + 1, s + w, w);
    }
}

int main(void) 
{
    int n;
    cin >> n;
    for (int i = 1, x, y; i <= n && 2 == scanf("%d %d", &x, &y); ++i)
        inc(i, (x < 0 ? 1 : 0) + (y < 0 ? 2 : 0));
    int q;
    cin >> q;
    char s[32];
    for (int i = 0, b, e; i < q && 3 == scanf("%s %d %d", s, &b, &e); ++i)
        if ('C' == *s) 
        {
            int v[4] = {0};
            query(b, e + 1, v);
            cout << v[0] << " " << v[1] << " " << v[3] << " " << v[2] << endl;
        } 
        else
            update(b, e + 1, 'X' == *s ? 2 : 1);
  return 0;
}
