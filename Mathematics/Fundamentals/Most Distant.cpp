#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    double mnx,mxx,mny,mxy; //min_x_axis  max_x_axis  min_y_axis  max_y_axis  
    int t;
    cin>>t;
    while(t--)
    {
        double a,b;
        cin>>a>>b;
        if(a==0)
        {
            mny=min(mny,b);
            mxy=max(mxy,b);
        }
        else
        {
            mnx=min(mnx,a);
            mxx=max(mxx,a);
            
        }
        
        
    }
        double mx=max(abs(mxx-mnx),abs(mny-mxy));//axis
        double q1=sqrt(mxx*mxx+mxy*mxy); //quadrant 1
        double q2=sqrt(mnx*mnx+mxy*mxy);    //2
        double q3=sqrt(mnx*mnx+mny*mny);    //3
        double q4=sqrt(mxx*mxx+mny*mny);    //4
    
        printf("%.10f",max(mx,max(q1,max(q2,max(q3,q4)))));
    
    return 0;
}
