#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef unsigned short uint;
unsigned int bitdata[2][50000 / 32 + 1];

int evaluate_rep(uint *a, int n, int Max)
{
    uint *e = (uint *)malloc(50001 * sizeof(uint));
    if(NULL == e)
        return -2;
    uint *b = e;

    memset(bitdata, 0, sizeof(bitdata));
    unsigned int *bd0 = bitdata[0], *bd1 = bitdata[1];

    int rep = 0, r = 0;
    int m = 0, b_count;
    while( n > 0 )
    {
        b_count = 0;
        memset(bd0, 0, (Max / 32 + 1) * sizeof(unsigned int));
        uint *a1 = a, *a2, max_a = 0, max_b, *b1 = b, min_a = 50001, min_aa = 50001;
        for(int i = 0; i < n; ++i)
        {
            a2 = a + i + 1;
            for(int j = i + 1; j < n; ++j)
            {
                if(*a1 != *a2)
                {
                    uint d = (*a1 > *a2 ? *a1 - *a2 : *a2 - *a1);
                    if( (bd0[d >> 5] & (1 << (d & 31))) == 0)
                    {
                        bd0[d >> 5] |= (1 << (d & 31));
                        *b1++ = d;
                        ++b_count;
                        if(max_a < d)
                            max_a = d;
                        if(min_a > d)
                            min_a = d;
                        else if(min_aa > d)
                            min_aa = d;
                    }
                }
                ++a2;
            }
            ++a1;
        }
        if(max_a == min_a * b_count)
        {
            r = b_count + 1;
            break;
        }
        uint mm, xx = min_aa - min_a;
        if(xx > 1)
        {
            uint rr = min_a % xx;
            for(mm = min_a; mm <= max_a; ++mm)
            {
                if( (bd0[mm >> 5] & (1 << (mm & 31))) == 0)
                    if(mm % xx != rr)
                        break;
            }
            if(mm <= max_a)
                xx = 1;
        }
        int bb = 1, tt = 0, ss = 0, max_tt = 0;
        for(mm = xx; mm <= max_a; mm += xx)
        {
            if( (bd0[mm >> 5] & (1 << (mm & 31))) == 0)
            {
                ++tt;
                bb = 0;
            }
            else
            {
                if(max_tt < tt)
                {
                    max_tt = tt;
                }
                tt = 0;
                if(bb)
                    ++ss;
            }
        }
        if(ss >= max_tt)
        {
            r = max_a / xx + 1;
            break;
        }

        // swap a and b
        { uint *c = b; b = a; a = c; }
        { unsigned int *t = bd0; bd0 = bd1; bd1 = t; }

        n = b_count;
        max_b = max_a;
        Max = max_a;
        m = 1 - m;
        rep++;
    }

    free(e);

    return rep + r;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n;
    scanf("%d", &n);

    uint *a = (uint *)malloc(100001 * sizeof(uint));
    if(NULL == a)
        return -1;

    memset(bitdata, 0, sizeof(bitdata));
    int maxa = -1, mina = 50001, minaa = 50001, count = 0;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", (int *)&a[i]);
        if( (bitdata[0][a[i] >> 5] & (1 << (a[i] & 31))) == 0)
        {
            bitdata[0][a[i] >> 5] |= (1 << (a[i] & 31));
            count++;
        }
            
        if(mina >= a[i])
            mina = a[i];
        else if(minaa > a[i])
            minaa = a[i];
        if(maxa < a[i])
            maxa = a[i];
    }
    if(maxa == mina * count)
       printf("%d", count);
    else if( (maxa - mina) == (minaa - mina) * (count - 1) )
       printf("%d", count);
    else
       printf("%d", evaluate_rep(a, n, maxa));

    free(a);

    return 0;
}
