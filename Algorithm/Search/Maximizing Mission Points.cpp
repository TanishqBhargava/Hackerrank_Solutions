#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void extend(vector< vector< vector<int> > > &grid, int gx, int gy, vector<int> &p){
    if (gx<0 || gy<0 || gx>=grid.size() || gy>=grid[gx].size()) {
        return;
    }
    p.insert(p.end(), grid[gx][gy].begin(), grid[gx][gy].end());
}


int main(){
    
    int n;
    int x;
    int y;
    
    vector<int> c_lat;
    vector<int> c_long;
    vector<int> c_h;
    vector<int> c_p;
       
    multimap<int,int> mm;
    multimap<int,int> mmx;
    multimap<int,int> mmy;
       
    cin >> n >> x >> y;

    int X=x;
    int Y=y;
    if (X<=1000) X=1000;
    if (Y<=1000) Y=1000;     

    int N=200000;
    
    vector< vector< vector<int> > > grid( N/X+1, vector< vector<int> >(N/Y+1));
    vector< vector<int> > acc(n);

    
    for(int a0 = 0; a0 < n; a0++){
        int latitude;
        int longitude;
        int height;
        int points;
        cin >> latitude >> longitude >> height >> points;
        c_lat.push_back(latitude);
        c_long.push_back(longitude);
        c_h.push_back(height);
        c_p.push_back(points);
        mm.insert(pair<int,int>(height,a0));
//        mmx.insert(pair<int,int>(latitude,a0));
//        mmy.insert(pair<int,int>(longitude,a0));
        
        int gx = latitude/X;
        int gy = longitude/Y;
        grid[gx][gy].push_back(a0);
    }
    
    long long int allbest=0;
    if ((long long int)(N/x)*(long long int)(N/y)<=200LL){
        map<long long int, int> bv;
        auto it=mm.rbegin();
        int c1=it->second;
        bv[c_p[c1]]=c1;
        if (allbest<c_p[c1]){
            allbest=c_p[c1];
        }
        for(++it;it!=mm.rend();++it){
            c1 = it->second;
            long long int v = c_p[c1];
            for(auto it2=bv.rbegin();it2!=bv.rend();it2++){
                int c2=it2->second;
                if (abs(c_lat[c1]-c_lat[c2])<=x && abs(c_long[c1]-c_long[c2])<=y) {
                    if (it2->first>0) {
                        v=c_p[c1]+it2->first;
                    } else {
                        v=c_p[c1];
                    }                                    
                    break;
                }
                
            }
            bv[v]=c1;
            if (allbest<v){
                allbest=v;
            }
            
            
        }
        
    } else {

        for(int c1=0;c1<n;c1++){
            vector<int> p;
            int gx=c_lat[c1]/X;
            int gy=c_long[c1]/Y;
            extend(grid,gx-1,gy-1,p);
            extend(grid,gx-1,gy  ,p);
            extend(grid,gx-1,gy+1,p);
            extend(grid,gx  ,gy-1,p);
            extend(grid,gx  ,gy  ,p);
            extend(grid,gx  ,gy+1,p);
            extend(grid,gx+1,gy-1,p);
            extend(grid,gx+1,gy  ,p);
            extend(grid,gx+1,gy+1,p);

            for(int j=0;j<p.size();j++){
                int c2 = p[j];
                if (c1!=c2 && c_h[c1]<c_h[c2] && abs(c_lat[c1]-c_lat[c2])<=x && abs(c_long[c1]-c_long[c2])<=y ) {
                    acc[c1].push_back(c2);
                }                                    
            }
        }    

        vector<long long int> best(n);

        for(auto it=mm.rbegin();it!=mm.rend();++it){
            int c1 = it->second;
            best[c1]=c_p[c1];
            if (allbest<best[c1]){
                allbest = best[c1];
            }
            if (best[c1]+allbest<0) continue;
            for(int i=0;i<acc[c1].size();++i){
                int c2 = acc[c1][i];
                if (c_p[c1]+best[c2]>best[c1]){
                    best[c1] = c_p[c1]+best[c2];
                    if (allbest<best[c1]){
                        allbest = best[c1];
                    }
                }
            }
        }
    }

    cout<<allbest<<endl;
    
    return 0;
}
