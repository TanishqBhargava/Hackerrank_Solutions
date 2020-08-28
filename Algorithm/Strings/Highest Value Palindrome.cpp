#include <bits/stdc++.h>

using namespace std;

string richieRich(string s, int n, int k){
   int lives=k;
   vector<bool> mod(n,false);  
   string temp(s); 
    
   for (int i=0;i<n/2;i++) 
   {
       if (temp[i]!=temp[n-i-1]) {mod[i]=true;lives--;}
       if (temp[i]<temp[n-i-1]) temp[i]=temp[n-i-1]; else if (temp[i]>temp[n-i-1]) temp[n-i-1]=temp[i];
       if (lives<0) return "-1";       
   }
    int j=0;
   while ((lives>0)&&(j<n/2))
   {
      if (temp[j]!='9'){
      if (mod[j]) lives++;
      if (lives>1) {temp[j]='9';temp[n-j-1]='9'; lives-=2;}
      }       
      j++;        
   }
    if (n%2==1) {if (lives>0) temp[n/2]='9';} 
    return temp;
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    cin >> s;
    string result = richieRich(s, n, k);
    cout << result << endl;
    return 0;
}
