#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the handshake function below.
 */
int handshake(int n) {
    
    if(n == 1)
    {
        return 0;
    }
    else {
        return (n-1)+(handshake(n-1));
    }
    
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

        int result = handshake(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
