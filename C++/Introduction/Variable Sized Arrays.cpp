#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin >> n >> q;
    vector<vector<int>>a(n);
    for(int i = 0;i < n; i++)
    {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++)
        {
            int val;
            cin>>val;
            a[i].push_back(val);
        } 
    }
    for(int i = 0; i < q; i++)
    {
        int x,y;
        cin >> x >> y;
        cout << a.at(x).at(y) << endl;
    }
    return 0;
}
