#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    vector<int> list;
    cin >> n;
    while(cin >> n) 
        list.push_back(n);
    sort(list.begin(), list.end());
    for(auto n : list) 
        cout << n << " ";
    return 0;
}
