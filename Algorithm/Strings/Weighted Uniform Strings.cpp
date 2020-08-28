#include <bits/stdc++.h>

using namespace std;
int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;    
    vector<bool> vb(10*1000*1000);    
    int mul=1;
    char prev='1';
    for(int j=0; j<s.size(); j++){
        int w = s[j]-'a'+1;
        if(s[j]==prev) {mul++; w*=mul;}
        else mul=1;
        prev = s[j];
        vb[w] = true;
    }    
    for(int a0 = 0; a0 < n; a0++){
        int x;
        cin >> x;
        if(vb[x]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }    
    return 0;
}
