#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the halloweenParty function below.
 */
long long halloweenParty(int k) {
    /*
     * Write your code here.
     */
    long long res = (k/2);
    res*=(k-k/2);
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int k;
        cin >> k;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = halloweenParty(k);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
