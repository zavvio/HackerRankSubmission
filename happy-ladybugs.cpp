// https://www.hackerrank.com/challenges/happy-ladybugs
#include <bits/stdc++.h>

using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs(string b) {
    bool happy;
    int count[27] = {0};
    
    happy = true;
    for (int i = 0; i < b.length(); i++) {
        if (b[i] == '_') {
            count[26]++;
        } else {
            count[b[i] - 'A']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] == 1) {
            happy = false;
        }
    }
    if (count[26] <= 0) {
        if ((b[0] != b[1]) || (b[b.length() - 2] != b[b.length() - 1])) {
            happy = false;
        } else {
            for (int i = 1; i < b.length() - 1; i++) {
                if (b[i - 1] != b[i] && b[i] != b[i + 1]) {
                    happy = false;
                    break;
                }
            }
        }
    }

    return happy ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
