/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include<bits/stdc++.h>>
using namespace std;

int main()
{
    int T, N, K, L, H, M, ans, rem, dVal;
    cin >> T;
    while(T--)
    {
        cin >> N;
        cin >> K;
        L = 1;
        H = N + 1;
        while(L + 1 < H)
        {
            M = L + ((H - L) / 2);
            rem = N % M;
            dVal = N / M;
            ans = rem * (dVal + 1) * (M - rem) * dVal + (rem) * (rem - 1) * (dVal + 1) * (dVal + 1) / 2 + (M - rem) * (M - rem - 1) * (dVal) * dVal / 2 ;
            if(ans < K) 
                L = M;
            else
                H = M;
        }
        cout << H << endl;
    }
    return 0;
}
