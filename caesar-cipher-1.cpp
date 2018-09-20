// https://www.hackerrank.com/challenges/caesar-cipher-1
#include <bits/stdc++.h>

using namespace std;

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {
    // cout << "size = " << sizeof(s[0]) << endl;
    // cout << "size = " << sizeof(1) << endl;
    // cout << "size = " << sizeof(s) << endl;
    // cout << "size = " << sizeof(string) << endl;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += k % 26;
            if (s[i] > 'Z') {
                s[i] -= 26;
            }
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            // need to do the subtraction because size of a char is 1 byte, z = 122, will overflow 127 quite easily
            s[i] -= 'a';
            s[i] += k % 26;
            if (s[i] >= 26) {
                s[i] -= 26;
            }
            s[i] += 'a';
        }
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
