#include <iostream>
#include <iomanip> 
using namespace std;

int main()
{
    int T; cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while(T--) 
    {
        double A; cin >> A;
        double B; cin >> B;
        double C; cin >> C;

        /* BEGIN: unlocked */
          // Sample solution:
            cout << left << hex << showbase << nouppercase << (long long) A << endl;

            // One decimal place, right aligned, show sign, and fill left with underscores
            cout << showpos << fixed << setfill('_') << setw(15) << right << setprecision(2) << B << endl;

            // Scientific notation with 9 decimal places
            cout << noshowpos << uppercase << scientific << setprecision(9) C << endl;
        /* END: unlocked */
    }
    return 0;
}
