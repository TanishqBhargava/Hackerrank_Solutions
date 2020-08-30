#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the deforestation function below.
 */
int gr[501];

int dfs(int u, int p, vector<vector<int>>& G){
    for(auto ch : G[u]){
        if(ch != p) gr[u] ^= dfs(ch,u,G);
    }
    return u == 1 ? gr[u] : ++gr[u];
}


string deforestation(int n, vector<vector<int>> tree) {
    memset(gr, 0, sizeof(gr));
    vector<vector<int>> G(n+1);
    for(auto p : tree){
        G[p[0]].push_back(p[1]);
        G[p[1]].push_back(p[0]);
    }
    return dfs(1,-1,G) ? "Alice" : "Bob";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> tree(n-1);
        for (int tree_row_itr = 0; tree_row_itr < n-1; tree_row_itr++) {
            tree[tree_row_itr].resize(2);

            for (int tree_column_itr = 0; tree_column_itr < 2; tree_column_itr++) {
                cin >> tree[tree_row_itr][tree_column_itr];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = deforestation(n, tree);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
