#include <bits/stdc++.h>

using namespace std;

struct Edge
{
  int a;
  int b;
};

istream& operator>> (istream &is, Edge &e)
  {is >> e.a >> e.b; return is;}

int main()
{
  size_t n;
  int k;
  cin >> n >> k >> ws;
  vector<int> trail;
  trail.reserve(n);
  vector<int> sorted;
  sorted.reserve(n);
  vector<int> parent;
  parent.resize(100001,0);
  long long count = 0;
  for (Edge e; cin >> e;)
  {
    parent[e.b] = e.a;
    while (!trail.empty() && trail.back() != e.a)
    {
      sorted.erase(lower_bound(begin(sorted),end(sorted),trail.back()));
      trail.pop_back();
    }
    if (trail.empty()) // recover
    {
      for (int p = e.a; p; p = parent[p])
      {
        trail.push_back(p);
        sorted.push_back(p);
      }
      reverse(begin(trail),end(trail));
      sort(begin(sorted),end(sorted));
    }
    count += distance(lower_bound(begin(sorted),end(sorted),e.b-k),
              upper_bound(begin(sorted),end(sorted),e.b+k));
    sorted.insert(upper_bound(begin(sorted),end(sorted),e.b),e.b);
    trail.push_back(e.b);
  }
  cout << count << '\n';
  return 0;
}
