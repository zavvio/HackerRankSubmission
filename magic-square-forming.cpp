// https://www.hackerrank.com/challenges/magic-square-forming
#include <bits/stdc++.h>

using namespace std;

int predefined[8][3][3] = {
    {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
    {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
    {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
    {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}}, 
    {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}}, 
    {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}}, 
    {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}}, 
    {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},  
};

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    int min_cost = 81, cost;
    for (int i = 0; i < 8; i++) {
        cost = 0;
        cost += abs(predefined[i][0][0] - s[0][0]);
        cost += abs(predefined[i][0][1] - s[0][1]);
        cost += abs(predefined[i][0][2] - s[0][2]);
        cost += abs(predefined[i][1][0] - s[1][0]);
        cost += abs(predefined[i][1][1] - s[1][1]);
        cost += abs(predefined[i][1][2] - s[1][2]);
        cost += abs(predefined[i][2][0] - s[2][0]);
        cost += abs(predefined[i][2][1] - s[2][1]);
        cost += abs(predefined[i][2][2] - s[2][2]);
        if (cost < min_cost) min_cost = cost;
    }
    return min_cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
