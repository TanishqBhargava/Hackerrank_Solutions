/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include<bits/stdc++.h>
using namespace std;
int sum = 0;
vector<int> *data;

int f(int n)
{
    int s = data[n].size(),t = 0;
    for(int i = 0; i < s ; ++i)
    {
        t += f(data[n][i]);
    }
    if(t % 2 == 1)
        ++sum;
    return t + 1;
}

int main()
{
    int a,b,i,x,y;
    cin >> a >> b;
    data = new vector<int>[a+1];
    for(i = 0; i < b; ++i)
    {
        cin >> x >> y;
        data[y].push_back(x);
    }
    f(1);
    cout << sum - 1 << endl;
    return 0;
}
