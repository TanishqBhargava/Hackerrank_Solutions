#include <bits/stdc++.h>

using namespace std;

// Complete the steadyGene function below.
bool validityCheck(map<char, int> dict, int limit){
    if(dict['A'] <= limit && dict['C'] <= limit && dict['G'] <= limit && dict['T'] <= limit){
        return true;
    }else{
       return false;
    }
}

int main() {
    int N, maxIndex = 0, out = 999999;
    map<char, int> dict;
    string str;
    cin >> N >> str;
    int limit = N / 4;
    for (int i = N - 1; i >= 0; i--){
        dict[str[i]]++;
        if(!validityCheck(dict, limit)){
            maxIndex = i + 1;
            dict[str[i]]--;
            break;
        }
    }
    for(int minIndex = -1; minIndex < N - 1 && maxIndex < N && minIndex < maxIndex; minIndex++){
        while(!validityCheck(dict, limit) && maxIndex < N){
            dict[str[maxIndex]]--;
            maxIndex++;
        }
         if(maxIndex > N || !validityCheck(dict, limit)){
            break;
        }
        int substringLength = max(0, maxIndex - minIndex - 1);
        if(substringLength < out){
            out = substringLength;
        }
        dict[str[minIndex + 1]]++;
    }
    cout << out << endl;
    return 0;
}
