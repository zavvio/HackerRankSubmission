// https://www.hackerrank.com/challenges/mars-exploration
#include <bits/stdc++.h>

using namespace std;

// Complete the marsExploration function below.
int marsExploration(string s) {
    int count = 0;
    for (int i = 0; i < s.length() / 3; i++) {
        if (s[i*3] != 'S') {
            count++;
        }
        if (s[i*3+1] != 'O') {
            count++;
        }
        if (s[i*3+2] != 'S') {
            count++;
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
