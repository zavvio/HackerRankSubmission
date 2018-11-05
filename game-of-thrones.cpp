// https://www.hackerrank.com/challenges/game-of-thrones
#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {
    int charCount[26] = {0};
    bool ok = true;
    for (char c : s) {
        charCount[c - 'a']++;
    }
    for (int i = 0 ; i < 26; i++) {
        if (charCount[i] % 2 == 1) {
            if (ok == true) {
                ok = false;
            } else {
                return "NO";
            }
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
