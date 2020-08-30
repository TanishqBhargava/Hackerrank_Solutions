#include <iostream>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long sum=1;
        for(int i=0;i<n-1;i++)
        {
            
            long long x;
            cin>>x;
            sum=((sum%1234567)*(x%1234567))%1234567;
            
        }
        cout<<sum<<endl;
    }
    return 0;
}
