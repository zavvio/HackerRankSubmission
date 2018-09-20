// https://www.hackerrank.com/challenges/append-and-delete
#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    int commonLength = 0, step;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == t[i]) {
            commonLength++;
        } else {
            break;
        }
    }
    step = s.length() + t.length() - 2 * commonLength;
    // cout << "Step: " << step << endl;
    // cout << sizeof(k) << ", " << sizeof(s.length());
    if (step > k) {
        return "No";
    } else if (step % 2 == k % 2) {
        return "Yes";
    } else if ((k - (int) s.length() - (int) t.length()) >= 0) {
        return "Yes";
    } else {
        return "No";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
