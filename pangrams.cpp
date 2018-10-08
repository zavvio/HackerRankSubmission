// https://www.hackerrank.com/challenges/pangrams
#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {
    bool checklist[26] = {false};
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            checklist[c - 'a'] = true;
        }
    }
    for (bool b : checklist) {
        if (b == false) {
            return "not pangram";
        }
    }
    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
