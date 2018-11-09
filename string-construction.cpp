// https://www.hackerrank.com/challenges/string-construction
#include <bits/stdc++.h>

using namespace std;

// Complete the stringConstruction function below.
int stringConstruction(string s) {
    int chars[26] = {0};
    int cost = 0;
    for (char c : s) {
        chars[c - 'a'] = 1;
    }
    for (int i : chars) {
        cost += i;
    }
    return cost;
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

        int result = stringConstruction(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
