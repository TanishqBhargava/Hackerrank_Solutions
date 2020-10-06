/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<pair<int, int> > vp;
    for(int i = 0; i < n; ++i) 
    {
        int t, f;
        cin >> t >> f;
        vp.push_back(make_pair(t + f, t - f));
    }
    sort(vp.begin(), vp.end());
    reverse(vp.begin(), vp.end());
    vector<int> last(vp.size(), numeric_limits<int>::max());
    for(int i = 0; i < vp.size(); ++i) 
    {
        *lower_bound(last.begin(), last.end(), vp[i].second) = vp[i].second;
    }
    cout << lower_bound(last.begin(), last.end(), numeric_limits<int>::max()) - last.begin() << endl;
    return 0;
}
