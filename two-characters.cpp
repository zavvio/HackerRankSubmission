// https://www.hackerrank.com/challenges/two-characters
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the alternate function below.
int alternate(string s) {
    bool exist[26] = {false}, valid;
    string charSet = "", buff;
    int maxLen = 0;
    // searching for existing characters
    for (char c : s) {
        exist[c - 'a'] = true;
    }
    // forming a string with existing character in alphabetical order
    for (int i = 0; i < 26; i++) {
        if (exist[i]) {
            charSet += 'a' + i;
        }
    }
    // cout << charSet << endl;
    // solving length for each pair of existing characters
    for (int i = 0; i < charSet.length() - 1; i++) {
        for (int j = i + 1; j < charSet.length(); j++) {
            buff = "";
            // forming new string with only the two characters in each pair
            for (char c : s) {
                if (c == charSet[i] || c == charSet[j]) {
                    buff += c;
                }
            }
            // check each new string for whether it's valid or not
            valid = true;
            for (int x = 0; x < buff.length() - 1; x++) {
                if (buff[x] == buff[x + 1]) {
                    valid = false;
                    break;
                }
            }
            // keep track of max valid string length
            if (valid && buff.length() > maxLen) {
                maxLen = buff.length();
            }
        }
    }
    return maxLen;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
