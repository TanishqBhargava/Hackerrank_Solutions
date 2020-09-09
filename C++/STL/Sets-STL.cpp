#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Q, x, y;
    set<int> s;
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        cin >> y;
        cin >> x;
        if(y == 1)
            s.insert(x);
        else if(y == 2)
            s.erase(x);
        else
        {
            set<int>::iterator it = s.find(x);
            if(it != s.end())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}
