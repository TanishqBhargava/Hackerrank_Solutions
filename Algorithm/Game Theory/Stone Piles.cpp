#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <vector>
#include <climits>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;


typedef vector< vector<bool> > myVector;


void compute_sg_fun(int prev, int start, int rest, int key, vector<int>& sg_fun, myVector& record) {

 for (int i = start; i <= rest / 2; i++) {
  if (rest-i > i) {
   int res = prev ^ sg_fun[i] ^ sg_fun[rest-i];
   record[key][res] = true;
   compute_sg_fun(prev ^ sg_fun[i], i+1, rest - i,key, sg_fun, record);
  }
 }

 int k = 0;

 while (record[key][k]) ++k;

 sg_fun[key] = k;
}






int main(void)


{

 myVector record(51, vector<bool>(51,false));
 vector<int> sg_fun(51,-1);
 sg_fun[0] = 0;
 sg_fun[1] = 0;
 sg_fun[2] = 0;
 sg_fun[3] = 1;


 for (int i = 4; i <= 50; i++) compute_sg_fun(0,1,i,i,sg_fun,record);
 
 int t; cin >> t;

 for (int i = 0; i < t; i++) {
  int n;
  cin >> n;

  int res = 0;

  for (int j = 0; j < n; j++) {
   int c; cin >> c;
   res = res ^ sg_fun[c];
  }

  printf("%s\n", res == 0 ? "BOB" : "ALICE");

 }

 return 0;

}
