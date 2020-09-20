#include<bits/stdc++.h>
using namespace std;
deque<int> A,B;
int N,T;
int C[200001];
int main()
{
    cin >> T;
    while(T--)
    {
        cin >> N;
        int ans = N;
        for(int i = 1; i <= N; ++i) 
            cin >> C[i];
        sort(C + 1, C + N + 1);
        for(int i = 1; i <= N;)
        {
            int j = i;
            while(j <= N && C[j] == C[i]) ++j;
            int k = j - i;
            if(C[i] == C[i - 1] + 1)
            {
                while(k&&!A.empty())
                {
                    B.push_back(A.front() + 1);
                    A.pop_front();
                    --k;
                }
            }
            while(k) B.push_front(1),--k;
            while(!A.empty()) ans = min(ans, A.front()), A.pop_front();
            swap(A,B);
            i = j;
        }
        while(!A.empty()) ans = min(ans, A.front()), A.pop_front();
        cout << ans << endl;
    }
    return 0;
}
