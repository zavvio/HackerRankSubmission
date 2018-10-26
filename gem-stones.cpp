// https://www.hackerrank.com/challenges/gem-stones
#include <bits/stdc++.h>

using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> arr) {
    int count[26] = {0}, gem = 0;
    for (string s : arr) {
        bool exist[26] = {false};
        for (char c : s) {
            exist[c - 'a'] = true;
        }
        for (int i = 0; i < 26; i++) {
            if (exist[i] == true) {
                count[i]++;
            }
        }
    }
    for (int i : count) {
        if (i == arr.size()) {
            gem++;
        }
    }
    return gem;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
