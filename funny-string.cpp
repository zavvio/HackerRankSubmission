// https://www.hackerrank.com/challenges/funny-string
#include <bits/stdc++.h>

using namespace std;

// Complete the funnyString function below.
string funnyString(string s) {
    int a[s.length()-1] = {0}, b[s.length()-1] = {0};
    for (int i = 0; i < s.length() - 1; i++) {
        a[i] = abs(s[i] - s[i+1]);
    }
    cout << endl;
    for (int i = s.length() - 1, j = 0; i > 0; i--, j++) {
        b[j] = abs(s[i] - s[i-1]);
    }
    cout << endl;
    for (int i = 0; i < s.length() - 1; i++) {
        if (a[i] != b[i]) {
            // cout << a[i] << " != " << b[i] << endl;
            return "Not Funny";
        }
    }
    return "Funny";
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

        string result = funnyString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
