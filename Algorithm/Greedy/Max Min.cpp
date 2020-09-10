/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N, K;
    cin >> N >> K;
    vector <int> k (N, 0);
    for (int i = 0; i < N; i++)
        cin >> k[i];
    sort (k.begin (), k.end ());
    vector <int> sols;
    for (int i = 0; i + K <= N; i++) 
        sols.push_back (k[i + K - 1] - k[i]);
    cout << *min_element (sols.begin(), sols.end()) << endl;
    return 0;
}
