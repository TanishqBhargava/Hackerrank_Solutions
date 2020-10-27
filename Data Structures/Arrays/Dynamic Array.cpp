/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N, Q, q, x, y, lastAnswer = 0;
    cin >> N >> Q;
    vector< vector< int > > vec(N, vector< int >(0));
    for(int i = 0; i < Q; i++) 
    {
        cin >> q >> x >> y;
        int X = (x ^ lastAnswer) % N;
        if(q == 1)
            vec[X].push_back(y);
        else 
        {
            lastAnswer = vec[X][y % vec[X].size()];
            cout << lastAnswer << endl;
        }
    }
    return 0;
}
