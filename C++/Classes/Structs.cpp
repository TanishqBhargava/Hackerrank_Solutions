#include <bits/stdc++.h>
using namespace std;

struct Student          //add code for struct here.
{
    unsigned age;
    string first_name;
    string last_name;
    unsigned standard;
};
int main() {
    Student st;
    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
    return 0;
}
