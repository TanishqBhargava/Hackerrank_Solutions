#include <bits/stdc++.h>
using namespace std;
 
int compare(pair<int, int> a, pair<int, int> b) 
{
    return a.first>b.first;
}

int main() 
{
    int n,k,a,b,cnt=0,sum=0,l=0;
    vector<pair<int, int>> z;
    cin>>n>>k;
    while(n--) 
    {
        cin>>a>>b;
        sum+=a;
        z.push_back(make_pair(a,b));
    }
    sort(z.begin(),z.end(),compare);
    for(int i=0;i<z.size();i++) 
    {
        if(z[i].second==0)
            cnt+=z[i].first;
        else 
        {
            if(l<k) 
            {
                cnt+=z[i].first;
                l++;
            }
            else 
                cnt-=z[i].first;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
