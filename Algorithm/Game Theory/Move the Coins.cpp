#include <cstdio>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;

#define N 1000000
int Time, n, x, y, q, c[N]; 
int L[N], R[N], ni[N][2], dep[N];
vector <int> ve[N];


void dfs(int k, int f) {
	L[k] = ++Time;
	ni[k][dep[k]] = c[k];
	for (int i = 0; i < (int) ve[k].size(); i++)
		if (ve[k][i] != f) {
			dep[ve[k][i]] = dep[k] ^ 1;
			dfs(ve[k][i], k);
			ni[k][0] ^= ni[ve[k][i]][0];
			ni[k][1] ^= ni[ve[k][i]][1];
		}
	R[k] = Time;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		ve[x].push_back(y);
		ve[y].push_back(x);
	}
	dep[1] = 0;
	dfs(1, 0);
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &x, &y);
		if (L[x] <= L[y] && L[y] <= R[x])
			printf("INVALID\n");
		else {
			if ((dep[y] + dep[x]) % 2 == 1) {
				if (ni[1][1])
					printf("YES\n");
				else
					printf("NO\n");
			}else {
				if (ni[1][1] ^ ni[x][1] ^ ni[x][0])
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
	}
}
