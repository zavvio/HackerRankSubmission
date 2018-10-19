// https://www.hackerrank.com/challenges/separate-the-numbers
#include <bits/stdc++.h>

using namespace std;

// Complete the separateNumbers function below.
void separateNumbers(string s) {
    long long start, next;
    string nextStr, sBackup = s;
    if (s.length() == 1 || s[0] == '0') {
        cout << "NO" << endl;
        return;
    }
    // incrementally parse for first number of longer length
    for (int i = 0; i < s.length() / 2; i++) {
        start = stoll(s.substr(0, i + 1)); // using stoi yields "abort called" error
        s.erase(s.begin(), s.begin() + to_string(start).length());
        // cout << "checking: " << start << " for " << s << endl;
        next = start + 1;
        // check next number in the front of the string to be +1
        while (s.length() >= to_string(next).length()) {
            nextStr = s.substr(0, to_string(next).length());
            // cout << "...comparing: " << next << " with " << nextStr << endl;
            if (stoll(nextStr) != next) {
                break;
            }
            s.erase(s.begin(), s.begin() + nextStr.length());
            next++;
        }
        if (s.length() == 0) {
            cout << "YES " << start << endl;
            return;
        }
        s = sBackup;
    }
    cout << "NO" << endl;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}
