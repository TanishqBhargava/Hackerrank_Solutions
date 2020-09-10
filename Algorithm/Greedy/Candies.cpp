#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long ChildCount=0;
    cin >> ChildCount;
    unsigned long rating[ChildCount],IndivCandyCount[ChildCount],i,CandyCount=0; 
    for(i = 0; i < ChildCount; i++)
    {
        IndivCandyCount[i]=0;
        cin >> rating[i];
        IndivCandyCount[i]=1;
    }
    for(i = ChildCount - 1; i > 0; i--)
        if(rating[i] < rating[i-1])
            IndivCandyCount[i-1] = IndivCandyCount[i] + 1;
    for(i = 0; i < ChildCount - 1; i++)
        if(rating[i] < rating[i+1] && IndivCandyCount[i] >= IndivCandyCount[i+1])
            IndivCandyCount[i+1] = IndivCandyCount[i] + 1;
    for(i = 0; i < ChildCount; i++)
        CandyCount += IndivCandyCount[i];
    cout << CandyCount;
}
