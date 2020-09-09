            cout << left << hex << showbase << nouppercase << (long long) A << endl;
            // One decimal place, right aligned, show sign, and fill left with underscores
            cout.precision(2);
            cout << showpos << fixed << setfill('_') << setw(15) << right << B << endl;
            // Scientific notation with 9 decimal places
            cout.precision(9);
            cout << noshowpos << uppercase << scientific << C << endl;
