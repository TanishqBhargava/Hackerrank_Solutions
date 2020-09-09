#include <bits/stdc++.h> 
using namespace std;

void printKMax(int A[], int N, int K){
	//Write your code here.
    deque<pair<int, int>> dq;
    for(int i = 0; i < N; i++){
        while(!dq.empty() && i - dq.front().second >= K){
            dq.pop_front();
        }
        while(!dq.empty() && dq.back().first <= A[i]){
            dq.pop_back();
        }
        dq.push_back({A[i], i});
        if(i >= K - 1){
            cout << dq.front().first << " ";
        }
    }
    cout << "\n";
}

int main(){
  
	int T;
	cin >> T;
	while(T > 0) {
		int N, K;
    	cin >> N >> K;
    	int i;
    	int A[N];
    	for(i = 0; i < N; i++)
      		cin >> A[i];
    	printKMax(A, N, K);
    	T--;
  	}
  	return 0;
}
