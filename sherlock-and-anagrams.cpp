// https://www.hackerrank.com/challenges/sherlock-and-anagrams
#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string s1, string s2) {
    int count1[26] = {0}, count2[26] = {0};
    for (char c : s1) {
        count1[c - 'a']++;
    }
    for (char c : s2) {
        count2[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }
    return true;
}

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int clen = 1, len = s.length(), count = 0;
    while (clen < len) {
        for (int i = 0; i < len - clen; i++) {
            for (int j = i + 1; j <= len - clen; j++) {
                if (isAnagram(s.substr(i, clen), s.substr(j, clen))) {
                    count++;
                }
            }
        }
        clen++;
    }
    return count;
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

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
