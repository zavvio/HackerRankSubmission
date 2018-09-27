// https://www.hackerrank.com/challenges/non-divisible-subset
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the nonDivisibleSubset function below.
int nonDivisibleSubset(int k, vector<int> S) {
    int remainder_count[k] = {0};
    int maxSize = 0, cutoff_index;
    // generate the count by remainder
    for (int i = 0; i < S.size(); i++) {
        remainder_count[S[i] % k]++;
    }
    // special case: remainder == 0, cannot add another number with remainder == 0
    if (remainder_count[0] > 0) {
        maxSize++; // only allow max of 1 number with remainder == 0
    }
    // special case 2: even number, e.g. 6 / 2 = 3, number with remainder 3 cannot add another number with remainder 3, similar to case of remainder 0
    if (k % 2 == 0) {
        cutoff_index = k / 2 - 1;
        if (remainder_count[k / 2] > 0) {
            maxSize++; // if exist, only allow one count
        }
    } else {
        cutoff_index = k / 2;
    }
    // all other number would only be evenly divisible by adding the its compliment number
    // e.g. for 6, [(1,5),(2,4)], so just pick one from each pair with larger count
    for (int i = 1; i <= cutoff_index; i++) {
        maxSize += max(remainder_count[i], remainder_count[k - i]);
    }
    // for (int i = 0; i < k; i++) {
    //     cout << "i = " << i << ", count = " << remainder_count[i] << endl;
    // }
    return maxSize;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string S_temp_temp;
    getline(cin, S_temp_temp);

    vector<string> S_temp = split_string(S_temp_temp);

    vector<int> S(n);

    for (int i = 0; i < n; i++) {
        int S_item = stoi(S_temp[i]);

        S[i] = S_item;
    }

    int result = nonDivisibleSubset(k, S);

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
