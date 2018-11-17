// https://www.hackerrank.com/challenges/richie-rich
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the highestValuePalindrome function below.
string highestValuePalindrome(string s, int n, int k) {
    int index_front, index_back;
    string original = s;
    // initializing two comparision "pointer" location based on parity of string length
    if (s.length() % 2 == 1) {
        index_front = s.length() / 2 - 1;
        index_back = s.length() - index_front - 1;
    } else {
        index_front = s.length() / 2 - 1;
        index_back = s.length() - index_front - 1;
    }
    // Step 1: just transform the string into palindromes, if possible
    while (k > 0 && index_front >= 0) {
        if (s[index_front] == s[index_back]) {
            index_front--;
            index_back++;
            continue;
        }
        if (s[index_front] > s[index_back]) {
            s[index_back] = s[index_front];
        } else {
            s[index_front] = s[index_back];
        }
        index_front--;
        index_back++;
        k--;
    }
    // cout << s << " - remaining k = " << k << endl;
    // Step 2: if no more changes available and string is not palindromes, "-1"
    while (index_front >= 0) {
        if (s[index_front] != s[index_back]) {
            s = "-1";
            break;
        }
        index_front--;
        index_back++;
    }
    // Step 3: if string is palindromes but more changes available
    if (k > 0) {
        index_front = 0;
        index_back = s.length() - 1;
        while (k > 0 && index_front < index_back) {
            if (s[index_front] == '9') {
                // skipping if it's already '9'
            } else if (s[index_front] != original[index_front] || s[index_back] != original[index_back]) {
                // if either one of the char in the pair changed, up both to '9' but decrease change count by only 1 to "replace" the original change with a better one
                s[index_front] = '9';
                s[index_back] = '9';
                k--;
            } else if (k >= 2) {
                // if neither char changed and at least 2 changes are available, up both to '9', decrease available changes by 2
                s[index_front] = '9';
                s[index_back] = '9';
                k -= 2;
            }
            index_front++;
            index_back--;
        }
        // trying to up the middle char if at least one change is still available
        if (k > 0 && index_front == index_back) {
            s[index_front] = '9';
        }
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
