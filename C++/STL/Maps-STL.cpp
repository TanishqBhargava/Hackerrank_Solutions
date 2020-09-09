#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Q, type, Y;
    string X;
    map<string, int> m;
    cin >> Q;
    while(Q--)
    {
        cin >> type >> X;
        switch(type)
        {
            case 1:
                cin >> Y;
                m[X] += Y;
                break;
            case 2:
                m.erase(X);
                break;
            case 3:
                cout << m[X] << endl;
                break;
        }
    }
    return 0;
}
