/*========================*\
|  ID: tanishqbhargava1    |
|  LANG: C++               |
\*========================*/
//Tanishq Bhargava
#include <bits/stdc++.h>
using namespace std;
int n, m, k, dist[100100], late[100100], bout[100100], arrival[100100];
vector<long long> peop[100100];
long long ans;

struct st 
{
    int i, j, spend;
    long long saved;
    st(int i, int j, long long saved, int spend) : i(i), j(j), saved(saved), spend(spend) {}
    bool operator < (st a) const 
    {
        if (saved != a.saved) 
        {
            return saved < a.saved;
        }
        return spend < a.spend;
    }
};

priority_queue<st> q;
int add(int i) 
{
    if (i == n) 
        return n;
    int spend = 1000000000, j = i + 1;
    if (dist[i]) 
    {
        spend = min(spend, dist[i]);
        long long saved = 0;
        for(j = i + 1; j <= n; ++j) 
        {
            --arrival[j];
            saved += bout[j];
            if (late[j] > arrival[j])
                break;    
            spend = min(spend, arrival[j] - late[j] + 1);
        }
        if (j > n) 
            j = n;
        st w(i, j, saved, spend);
        q.push(w);
        for(int q = i + 1; q <= j; ++q) ++arrival[q];
    }
    return j;
}

int main()
{
    cin >> n >> m >> k;
    --n;
    for(int i = 0; i < n; ++i) 
        cin >> dist[i];
    for(int i = 0; i < m; ++i) 
    {
        int t, s, e;
        cin >> t >> s >> e;
        --s;
        --e;
        late[s] = max(late[s], t);
        ++bout[e];
        peop[s].push_back(t);
    }
    late[n] = -1000000000;
    long long nowt = 0, carry = 0;
    for(int i = 0; i < n; ++i) 
    {
        arrival[i] = nowt;
        for(int j = 0; j < peop[i].size(); ++j) 
        {
            if (peop[i][j] < nowt)
                ans += nowt - peop[i][j];
            else
                ans += carry * (peop[i][j] - nowt);
            ++carry;
            nowt = max(peop[i][j], nowt);
        }
        ans += carry * dist[i];
        nowt += dist[i];
        carry -= bout[i + 1];
    }
    arrival[n] = nowt;
    int cur = 0;
    while(cur < n) 
        cur = add(cur);
    while(k && !q.empty()) 
    {
        st w = q.top();
        q.pop();
        if (w.spend >= k) 
        {
            ans -= w.saved * k;
            break;
        }
        ans -= w.saved * w.spend;
        k -= w.spend;
        dist[w.i] -= w.spend;
        for(int i = w.i + 1; i <= w.j; ++i) 
            arrival[i] -= w.spend;
        int x = w.i;
        while(x < w.j) 
            x = add(x);
    }
    cout << ans << endl;
    return 0;
}
