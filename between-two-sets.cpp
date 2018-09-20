// https://www.hackerrank.com/challenges/between-two-sets
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<string> split_string(string);

int gcd(int a, int b) {
    int t;
    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int gcd(vector<int> v) {
    int result = v[0];
    for (int i = 1; i < v.size(); i++) {
        result = gcd(result, v[i]);
    }
    return result;
}

int lcm(int a, int b) {
    if (a == 0 && b == 0) return 0;
    return abs(a * b) / gcd(a, b);
}

int lcm(vector<int> v) {
    int result = v[0];
    for (int i = 1; i < v.size(); i++) {
        result = lcm(result, v[i]);
    }
    return result;
}

/*
 * Complete the getTotalX function below.
 */
int getTotalX(vector<int> a, vector<int> b) {
    int lcm_a = lcm(a);
    int gcd_b = gcd(b);
    int count = 0, tmp = lcm_a;
    while (tmp <= gcd_b) {
        if (gcd_b % tmp == 0) {
            count++;
        }
        tmp += lcm_a;
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int a_itr = 0; a_itr < n; a_itr++) {
        int a_item = stoi(a_temp[a_itr]);

        a[a_itr] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split_string(b_temp_temp);

    vector<int> b(m);

    for (int b_itr = 0; b_itr < m; b_itr++) {
        int b_item = stoi(b_temp[b_itr]);

        b[b_itr] = b_item;
    }

    int total = getTotalX(a, b);

    fout << total << "\n";

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
