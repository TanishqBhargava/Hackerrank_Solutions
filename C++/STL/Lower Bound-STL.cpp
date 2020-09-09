#include <bits/stdc++.h>
using namespace std;

int main()
{
   int N;
   cin >> N;
   vector<int> V(N);
   for(auto & v : V)
      cin >> v;
   int Q;
   cin >> Q;
   while(Q--)
   {
      int Y;
      cin >> Y;
      auto it = lower_bound(V.begin(), V.end(), Y);
      cout << (*it == Y ? "Yes " : "No ") << (it - V.begin() + 1) << endl;
   }
   return 0;
}
