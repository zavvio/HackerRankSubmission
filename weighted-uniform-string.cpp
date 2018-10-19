// https://www.hackerrank.com/challenges/weighted-uniform-string
#include <bits/stdc++.h>
#include <set>

using namespace std;

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries) {
    vector<string> soln;
    set<int> possibleWeights; // no duplicate value allowed for set
    char c;
    int weight;
    
    // first, generate all possible weight values
    for (int i = 0; i < s.length(); i++) {
        c = s[i];
        weight = 0;
        // for each character, look ahead for the same char, log substrings' weight
        for (int j = i; j < s.length(); j++) {
            if (s[j] == c) {
                weight += c - 'a' + 1;
                possibleWeights.insert(weight);
            } else {
                // bypass for index i to next different char
                i = j - 1;
                break;
            }
        }
    }
    
    // simply query target weight in possibleWeights set (set is internally sorted as well)
    for (int q : queries) {
        if (possibleWeights.find(q) != possibleWeights.end()) {
            soln.push_back("Yes");
        } else {
            soln.push_back("No");
        }
    }
    return soln;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
