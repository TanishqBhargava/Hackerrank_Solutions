#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector <int> a(n),b(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    for (int i = 0; i < n; i++) 
        cin >> b[i];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (a[i] == b[j]) 
            {
                k++;
                b[j] = -5;
                j = n;
            }
    }
    if (k < n) 
        k++; 
    else 
        k--;
    cout << k << endl;
    return 0;
}
