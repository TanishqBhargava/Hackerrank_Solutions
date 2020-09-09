#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, a, x, b;
    vector <int> v;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    cin >> x >> a >> b;
    v.erase(v.begin() + x - 1);
    v.erase(v.begin() + a - 1, v.begin() + b - 1);
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0; 
}
