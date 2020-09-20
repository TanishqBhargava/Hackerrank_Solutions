#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int h[n];
    for (int i=0;i<n;i++) 
      cin >> h[i];
    int e=0;
    for (int i=n-1;i>=0;i--) 
      e=(e+h[i]+1)/2;
  cout << e;
}
