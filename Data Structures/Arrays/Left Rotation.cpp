/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    long int n, d;
    cin >> n >> d;
    long int a[n];
    for(long int i = 0; i < n; i++)
        cin >> a[i];
    for(long int i = d; i < n; i++)
        cout << a[i] << " ";
    for(long int i = 0; i < d; i++)
        cout << a[i] << " ";
    return 0;
}
