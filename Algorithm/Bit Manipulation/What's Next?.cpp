#include <bits/stdc++.h>
#define ll long long int
using namespace std; 
int main() { int t;

cin>>t; while(t--){

ll n;
cin>>n;
vector <ll> arr(n);
for(int i=0;i<n;i++)
    cin>>arr[i];
    bool a=false;
    ll lastval;
    ll lastidx=-1;
    ll last;
    bool re=false;
    int i;
for( i=n-1;i>=0;i--)
{

    if(i%2!=0&&!a)
    {

        lastval=arr[i];
        lastidx=i;
    }

    if(i%2==0)
{

    a=true;
    last=i;
}

    if(i%2!=0&&arr[i]!=0&&a)
    {   re =true;
       arr[i]--;
       arr[i+1]--;
       if(arr[i]==0&&arr[i+1]==0)
       {

           arr[i-1]++;
           if(lastidx!=-1)
           {

               arr[lastidx]++;
           }
           else{
            arr[i+1]=1;
           }
           break;
       }
       else if(arr[i]==0)
       {
           arr[i-1]+=1;
           if(lastidx!=-1)
           {
               swap(arr[i+1],arr[lastidx]);
               arr[i+1]++;


           }
           else
          arr.insert(arr.begin()+i+1,1);
        //   arr[i+1]=0;
           break;
       }

      else{
       if(lastidx!=-1)
       {

           swap(arr[lastidx],arr[i+1]);
           arr[i+1]++;
           arr.insert(arr.begin()+i+1,1);
       }
       else
       {

           arr.insert(arr.begin()+i+1,1);
           arr.insert(arr.begin()+i+2,1);  // /4 5 3 4 1     0 0 0 0 1   0 0 0 1 0
       }

        break;

      }
    }
}
if(re==false)
{

    i++;
    if(lastidx!=-1){
    arr[i]--;
    arr[lastidx]++;
    swap(arr[lastidx],arr[i]);
    arr.insert(arr.begin(),1);}
    else
    {

        arr[i]--;
        arr.insert(arr.begin(),1);
         arr.insert(arr.begin(),1);
    }

}
int sizee=arr.size();
for(int i=0;i<arr.size();i++)
{

    if(arr[i]==0)
        sizee--;
}
cout<<sizee<<endl;
for(int i=0;i<arr.size();i++) {

    if(arr[i]>0)
    cout<<arr[i]<<" ";


    }
    cout<<endl;
}}
