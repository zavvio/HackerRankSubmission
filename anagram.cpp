// https://www.hackerrank.com/challenges/anagram
#include <bits/stdc++.h>

using namespace std;

// Complete the anagram function below.
int anagram(string s) {
    int countFront[26] = {0}, countBack[26] = {0}, change = 0;
    if (s.length() % 2 == 1) {
        return -1;
    }
    for (int i = 0; i < s.length() / 2; i++) {
        countFront[s[i] - 'a']++;
    }
    for (int i = s.length() / 2; i < s.length(); i++) {
        countBack[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (countFront[i] > countBack[i]) {
            change += countFront[i] - countBack[i];
        }
    }
    return change;
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

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
