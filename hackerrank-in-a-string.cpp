// https://www.hackerrank.com/challenges/hackerrank-in-a-string
#include <bits/stdc++.h>

using namespace std;

// Complete the hackerrankInString function below.
string hackerrankInString(string s) {
    string model = "hackerrank";
    bool matched = false;
    for (int i = 0, j = 0; i < s.length() && j < model.length(); i++) {
        if (s[i] == model[j]) {
            j++;
            if (j == model.length()) {
                matched = true;
            }
        }
    }
    return matched ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = hackerrankInString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
