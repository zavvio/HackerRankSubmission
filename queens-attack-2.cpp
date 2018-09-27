// https://www.hackerrank.com/challenges/queens-attack-2
#include <bits/stdc++.h>
/*
88587 9
20001 20003
20001 20002
20001 20004
20000 20003
20002 20003
20000 20004
20000 20002
20002 20004
20002 20002
564 323

// traditional math graph coordinate, north east side is positive X & Y

0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 1 1 1 0     20002
0 0 1 X 1 0     20001
0 0 1 1 1 0     20000 (x-axis)
20000     20005 (y-axis)
*/
using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int count = 0, d;
    int dN = n - r_q, dS = r_q - 1, dW = c_q - 1, dE = n - c_q;
    int dNW = min(dN, dW), dNE = min(dN, dE), dSW = min(dS, dW), dSE = min(dS, dE);
    double slope;
    // For each direction, keep track of the shortest distance; update for each new obstacle
    for (vector<int> v : obstacles) {
        if (v[0] == r_q) { // same row
            if (v[1] > c_q) { // East
                d = v[1] - c_q;
                if (d < dE) {
                    dE = d - 1;
                }
            } else { // West
                d = c_q - v[1];
                if (d < dW) {
                    dW = d - 1;
                }
            }
            // cout << "horizontal\n";
        } else if (v[1] == c_q) { // same column
            if (v[0] > r_q) { // North
                d = v[0] - r_q;
                if (d < dN) {
                    dN = d - 1;
                }
            } else { // South
                d = r_q - v[0];
                if (d < dS) {
                    dS = d - 1;
                }
            }
            // cout << "vertical\n";
        } else {
            slope = ((double) v[0] - (double) r_q) / ((double) v[1] - (double) c_q);
            // cout << "slope = " << slope << endl;
            if (slope == 1) {
                if (v[1] > c_q) { // North East
                    d = min(v[1] - c_q, v[0] - r_q);
                    if (d < dNE) {
                        dNE = d - 1;
                    }
                } else { // South West
                    d = min(c_q - v[1], r_q - v[0]);
                    if (d < dSW) {
                        dSW = d - 1;
                    }
                }
            } else if (slope == -1) {
                if (v[1] > c_q) { // South East
                    d = min(v[1] - c_q, r_q - v[0]);
                    if (d < dSE) {
                        dSE = d - 1;
                    }
                } else { // North West
                    d = min(c_q - v[1], v[0] - r_q);
                    if (d < dNW) {
                        dNW = d - 1;
                    }
                }
            }
        }
    }
    // cout << dN << ", " << dS << ", " << dW << ", " << dE << ", " << dNW << ", " << dNE << ", " << dSW << ", " << dSE << endl;
    return dN + dS + dW + dE + dNW + dNE + dSW + dSE;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
