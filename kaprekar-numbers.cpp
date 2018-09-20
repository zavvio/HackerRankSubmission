// https://www.hackerrank.com/challenges/kaprekar-numbers
#include <bits/stdc++.h>

using namespace std;

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    int d;
    string s, l, r;
    bool b = true;
    for (int i = p; i <= q; i++) {
        d = to_string(i).length();
        s = to_string((long)i*(long)i);
        l = s.substr(0, s.length() - d);
        if (l == "") {
            l = "0";
        }
        r = s.substr(s.length() - d);
        if (stoi(l) + stoi(r) == i) {
            cout << i << " ";
            b = false;
        }
        // cout << i << ", " << s << ", " << l << " = " << stoi(l) << ", " << r << " = " << stoi(r) << endl;
    }
    if (b) {
        cout << "INVALID RANGE" << endl;
    }
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
