/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
const int M = 26;
string s;
vector<int> alph_cnt(M),need_cnt(M);

int main() 
{
    cin >> s;
    for(int i = 0; i < s.size(); ++ i)
        ++ alph_cnt[s[i] - 'a'];
    for(int i = 0; i < M; ++ i)
        need_cnt[i] = alph_cnt[i]/2;
    reverse(s.begin(), s.end());
    string ans = "";
    int id = 0;
    while(ans.size() < s.size()/2)
    {
        int min_id = -1;
        while(1)
        {
            char ch_id = s[id];
            if(need_cnt[(ch_id - 'a')] > 0 && (min_id < 0 || ch_id < s[min_id]))
                min_id = id;
            -- alph_cnt[(ch_id - 'a')];
            if(alph_cnt[(ch_id - 'a')] < need_cnt[(ch_id - 'a')])
                break;
            ++ id;
        }
        for(int i = min_id + 1; i <= id; ++ i)
            ++ alph_cnt[s[i] - 'a'];
        ans += s[min_id];
        -- need_cnt[s[min_id]-'a']; 
        id = min_id + 1;
    }
    cout<<ans<<endl;
    return 0;
}
