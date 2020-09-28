/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n,m,k;cin>>n>>m>>k;
    const int nm=n*m;string s;
    for(int i=0;i<n;i++)
    {
        string t;
        cin>>t;
        s+=t;
    }
    vector<pair<double,vector<double>>> e(nm,{0,vector<double>(nm)});
    for(int i=0;i<nm;i++)
        e[i].second[i]=-1;
    unordered_map<int,int> t;
    for(int i=0;i<k;i++)
    {
        int x,y,z;
        cin>>x>>y;
        x=m*(x-1)+(y-1);
        cin>>y>>z;
        y=m*(y-1)+(z-1);
        t[x]=y;
        t[y]=x;
    }
    int sp;
    for(int i=0;i<nm;i++) 
    {
        if(s[i]=='%')
            e[i].first=1;
        if(s[i]=='A')
            sp=i,s[i]='O';
        if(s[i]=='O')
        {
            int i2=i;
            if(t.count(i))i2=t[i];
            vector<int> x,d;
            if(i2%m)x.push_back(i2-1);
            if(i2%m<m-1)x.push_back(i2+1);
            if(i2/m)x.push_back(i2-m);
            if(i2/m<n-1)x.push_back(i2+m);
            for(int y:x)if(s[y]!='#')
                d.push_back(y);
            for(int x:d)
                e[i].second[x]=1./d.size();
        }
    }
    //if trapped: set to 0.
    //for(auto&x:e){for(auto y:x.second)cout<<y<<" ";cout<<"| "<<x.first;cout<<endl;}
    for(int i=0;i<nm;i++) 
    {
        if(i==sp)continue;
        vector<int> u;
        for(int j=0;j<nm;j++)
            if(j!=i && e[i].second[j])
                u.push_back(j); //should speed things up since sparse
        #define reduce(j)                                   \
        if(e[j].second[i])                                  \
        {                                                   \
            double mul=e[j].second[i]/e[i].second[i];       \
            e[j].first-=mul*e[i].first;                     \
            for(int x:u)e[j].second[x]-=mul*e[i].second[x]; \
            e[j].second[i]=0; /*exact removal*/             \
        }
        if(sp<i) 
            reduce(sp);
        for(int j=i+1;j<nm;j++) 
            reduce(j);
    }
    cout.precision(17);
    cout<<fixed<<-e[sp].first/e[sp].second[sp];
}
