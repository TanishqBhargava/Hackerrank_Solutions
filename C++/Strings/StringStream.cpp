#include <bits/stdc++.h>
using namespace std;

vector<int> parseInts(string str) {
    // Complete this function
    stringstream ss(str);
    vector<int> res; //making a new vector res in which we will store the result...
    char ch;
    int temp;
    while(ss >> temp)   
    {
        res.push_back(temp);
        ss >> ch;
    }
    return res;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    } 
    return 0;
}
