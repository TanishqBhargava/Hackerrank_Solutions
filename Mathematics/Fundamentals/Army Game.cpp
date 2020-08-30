#include <bits/stdc++.h>

using namespace std;
int main(){

         int l,b;
         cin>>l>>b;
         int sum4=0;
         int sum2=0;
         int tot=0;// this keeps the count of the number of        supplies
         int prod=l*b;

      // count the number of 4 blocks ( the largest range i.e 4    blocks = 1 supply  )
         sum4=(l/2) *( b/2);// this gives the number of  supplies for 4 unit blocks 
        
         tot+=sum4;//add the no. of supplies till now

         prod-=sum4*4;  // deduct the number of blocks taken out 
      
         sum2=prod/2; // count the number of 2 blocks ( the second largest range i.e 2 blocks = 1 supply )
         tot+=sum2;
         prod-=sum2*2; // deduct the number of blocks taken out 
         tot+=prod; // finally add the no of 1's remaining ( 1   block = 1 supply)
         
         cout<<tot; // finally print the total number of supplies 

         return 0;

     }
