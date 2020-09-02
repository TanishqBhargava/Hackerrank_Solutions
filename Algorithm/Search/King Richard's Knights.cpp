#include <bits/stdc++.h>
using namespace std;

int S,N,L;

typedef complex<int> pt;

struct state {
    pt orig;
    pt now;
    int d,idx;

    pt get_at(int x,int y) {
        x-=real(now);
        y-=imag(now);
        int rots=idx%4;
        swap(x,y);
        for(;rots--;) {
            int tmp=x;
            x=y;
            y=d-tmp;
        }
        swap(x,y);
        return pt(real(orig)+x,imag(orig)+y);
    }
    bool has(int x,int y) {
        return x>=real(orig) && y>=imag(orig) && x<=real(orig)+d && y<=imag(orig)+d;
    }

    pt rlook(int x,int y) {
        swap(orig,now);
        idx = 4-(idx%4);
        pt ans=get_at(x,y);
        idx=4-(idx%4);
        swap(orig,now);
        return ans;
    }
};
vector<state> vs;

int main() {
    cin>>N>>S;
    vs.push_back({pt(1,1),pt(1,1),N-1,0});
    for(int i=1;i<=S;i++) {
        int a,b,d; cin>>a>>b>>d;
        pt ul=vs.back().get_at(a,b);
        pt dr=vs.back().get_at(a+d,b+d);
        pt neworig={min(real(ul),real(dr)), min(imag(ul),imag(dr))};
        pt newnow={a,b};
        vs.push_back({neworig,newnow,d,i});
    }

    for(auto &st : vs) {
//        cout<<st.orig<<" "<<st.now<<" "<<st.d<<" "<<st.idx<<endl;
    }

cin>>L;
for(;L--;) {
long long w; cin>>w;
int x=w/N+1;
int y=w%N+1;
int lb=0,rb=S;
for(;lb<rb;) {
int mb=(lb+rb+1)/2;
if(vs[mb].has(x,y)) lb=mb;
else rb=mb-1;
}
pt p=vs[lb].rlook(x,y);
cout<<real(p)<<" "<<imag(p)<<endl;
}


}
