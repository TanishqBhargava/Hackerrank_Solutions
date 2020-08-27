#include <bits/stdc++.h>
using namespace std;
int main() 
  int t,i;
  cin >> t;
  string s;
  for(i=0;i<t;i++)
  {
    cin >> s;
    bool val = next_permutation(s.begin(), s.end());
    if (val == false)
    {
      cout << "no answer" << endl;
    }
    else
    {
      cout << s << endl;
    }
  }
  return 0;
}
