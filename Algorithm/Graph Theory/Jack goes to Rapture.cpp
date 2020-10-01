/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
vector < pair<int,int> > a[10000100];
int d[50500];

int get(int x)
{
    return x == d[x] ? x : d[x] = get(d[x]);
}

int main()
{
    int n, m, x, y, z;
    cin >> n >> m;
    while (m--)
    {
        cin >> x >> y >> z;
        a[z].push_back(make_pair(x, y));
    }
    for (int i = 1; i <= n; i++) 
        d[i] = i;
    for (int z = 1; z <= 10000000; z++)
        for (int i = 0; i < int(a[z].size()); i++)
        {
            d[get(a[z][i].first)] = get(a[z][i].second);
            if (get(1) == get(n))
            {
                cout << z << endl;
                return 0;
            }
        } 
    puts("NO PATH EXISTS");
}
