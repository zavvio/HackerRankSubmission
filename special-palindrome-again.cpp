// https://www.hackerrank.com/challenges/special-palindrome-again
// https://www.geeksforgeeks.org/count-special-palindromes-in-a-string/
#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    /* # Attempt 2
    long count = s.length();
    int front, back, count_c;
    bool is_palindrom;
    char c;
    for (int i = 2; i <= s.length(); i++) {
        for (int j = 0; j <= (s.length() - i); j++) {
            front = j;
            back = j + i - 1;
            is_palindrom = true;
            // # Attempt 1
            // Doing is_palindrom check for each substr is too slow
            // c = '?';
            // count_c = 0;
            // while (front < back) {
            //     if (s[front] != s[back]) {
            //         is_palindrom = false;
            //         break;
            //     }
            //     if (c != s[front]) {
            //         count_c++;
            //         if (count_c > 1) {
            //             is_palindrom = false;
            //             break;
            //         }
            //         c = s[front];
            //     }
            //     front++;
            //     back--;
            // }
            vector<int> freq(26, 0);
            for (int k = front; k <= back; k++) {
                freq[s[k] - 'a']++;
            }
            count_c = 0;
            for (int k = 0; k < freq.size(); k++) {
                if (freq[k] != 0) {
                    count_c++;
                    if (count_c == 1) {
                        front = freq[k];
                    } else if (count_c == 2) {
                        if (!((front == 1 && freq[k] != 1) || (front != 1 && freq[k] == 1))) {
                            is_palindrom = false;
                        }
                    } else if (count_c > 2) {
                        is_palindrom = false;
                    }
                }
            }
            if (is_palindrom) {
                count++;
                for (int x = j; x < (j + i); x++) {
                    cout << s[x];
                }
                cout << endl;
            }
        }
    }
    return count; */

    // # Attempt 3 - "Efficient Solution"
    vector<pair<char, int>> freq;
    int i, j, result = 0;
    for (i = 0; i < s.length(); i++) {
        j = i + 1;
        while (j < s.length() && s[i] == s[j]) {
            j++;
        }
        freq.push_back(make_pair(s[i], j - i));
        i = j - 1;
    }
    for (auto f : freq) { // 1+2+3+4+5 = (1+5)*5/2
        // cout << f.first << ", " << f.second << endl;
        result += f.second * (f.second + 1) / 2;
    }
    for (i = 1; i < (freq.size() - 1); i++) {
        if (freq[i].second == 1 && freq[i].first != freq[i-1].first &&
            freq[i-1].first == freq[i+1].first) {
            // cout << freq[i-1].first << freq[i].first << freq[i+1].first << endl;
            result += min(freq[i-1].second, freq[i+1].second);
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
