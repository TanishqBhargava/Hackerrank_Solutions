#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <set>
#include <map>
#include <cmath>
#pragma comment(linker,"/STACK:16777216")


using namespace std;
typedef long long ll;

string s1,s2;
int a[5003][5003];
int main()
{
    getline(cin,s1);
    getline(cin,s2);
    s1="^"+s1;
    s2="-"+s2;
    int l=s1.size()-1;
    for(int i=1;i<=l;i++)
    for(int j=1;j<=l;j++)
        {
            if(s1[i]==s2[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    cout<<a[l][l]<<endl;
    return 0;
}
