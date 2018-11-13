// https://www.hackerrank.com/challenges/sherlock-and-valid-string
#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    int occurance[26] =  {0}, occured = 0, total_occurance = 0, target = 0;
    bool valid = true;
    for (char c : s) {
        occurance[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (occurance[i] != 0) {
            occured++;
            total_occurance += occurance[i];
        }
    }
    if (occured == 1) { // only 1 character type, like "aaa"
        return "YES";
    }
    if ((total_occurance - 1) % (occured - 1) == 0) { // everything equal except an extra
        // e.g. aabbccdee, just remove 'd'
        target = (total_occurance - 1) / (occured - 1);
        for (int i = 0; i < 26; i++) {
            if (occurance[i] == 0) {
                continue;
            }
            if (valid) {
                if (occurance[i] == 1) {
                    valid = false;
                } else if (occurance[i] != target) {
                    return "NO";
                }
            } else if (occurance[i] != target) {
                return "NO";
            }
        }
        return "YES";
    } else if (total_occurance % occured != 0 && (total_occurance - 1) % occured != 0) {
        // cannot be evenly spread for all char types, or with 1 extra
        return "NO";
    } else {
        target = total_occurance / occured;
        for (int i = 0; i < 26; i++) {
            if (occurance[i] == 0) {
                continue;
            }
            if (valid) {
                if (occurance[i] != target) {
                    if (occurance[i] == target + 1 || occurance[i] == 1) {
                        valid = false;
                    } else {
                        return "NO";
                    }
                }
            } else {
                if (occurance[i] != target) {
                    return "NO";
                }
            }
        }
        return "YES";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
