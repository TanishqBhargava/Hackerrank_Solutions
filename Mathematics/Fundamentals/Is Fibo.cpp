#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
map<long, long> fibo;
long fibonacci(long n)
{
    if (fibo.find(n)!=fibo.end())    return fibo[n];
    fibo[n]=fibonacci(n-1)+fibonacci(n-2);
    return fibo[n];
}
string solve(long n) {
    fibo[0]=0;
    fibo[1]=1;
    long i=0;
    while(fibonacci(i)<n)
        i++;
    if (fibonacci(i)!=n)    return "IsNotFibo";
    return "IsFibo";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = solve(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
