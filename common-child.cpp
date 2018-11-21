// https://www.hackerrank.com/challenges/common-child
// https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    vector<vector<int>> traceback(s1.length()+1, vector<int>(s2.length()+1, 0));
    // fill traceback table, equal char pair increase length by 1;
    // otherwise, it's max{LCS[X(i-1), Y(j)], LCS[X(i), Y(j-1)]}
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i-1] == s2[j-1]) {
                traceback[i][j] = traceback[i-1][j-1] + 1;
            } else {
                traceback[i][j] = max(traceback[i-1][j], traceback[i][j-1]);
            }
        }
    }
    // Output traceback table
    // for (int i = 0; i <= s1.length(); i++) {
    //     for (int j = 0; j <= s2.length(); j++) {
    //         cout << traceback[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return traceback[s1.length()][s2.length()];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
