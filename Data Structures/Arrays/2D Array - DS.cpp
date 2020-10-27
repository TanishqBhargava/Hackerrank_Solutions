/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int arr[6][6],s;
    int m = INT_MIN;
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < 4; i++)
    {    
        for(int j = 0; j < 4; j++)
        {
            s = (arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2]);
            if(s > m)
                m = s;
        }    
    }
    cout << m; 
    return 0;
}
