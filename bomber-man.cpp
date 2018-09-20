// https://www.hackerrank.com/challenges/bomber-man
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

vector<string> split_string(string);

/*
5 5 5

t=1
...1.
.1.1.
.1...
..11.
.....

t=2
00020
02020
02000
00220
00000

t=3
1....
.....
....1
1....
11..1

t=4
20000
00000
00002
20000
22002

t=5
..111
.111.
.11..
..11.
.....

t=6
00222
02220
02200
00220
00000

t=7
1....
.....
....1
1....
11..1
*/

// Complete the bomberMan function below.
vector<string> bomberMan(int n, vector<string> grid) {
    int time = 2;
    if (n == 1) { // untouched when time == 1
        return grid;
    } else if (n % 2 == 0) { // all even number time slot has grid filled
        for (int i = 0; i < grid.size(); i++) {
            replace(grid[i].begin(), grid[i].end(), '.', 'O');
        }
        return grid;
    } else if (n > 5) { // repeating time = {2 -> 3 -> 4 -> 5 (-> 2...)}
        n = 4 + n % 4;
    }
    // first replace character to enable state tracking
    for (int i = 0; i < grid.size(); i++) {
        replace(grid[i].begin(), grid[i].end(), 'O', '2');
        replace(grid[i].begin(), grid[i].end(), '.', '1');
    }
    while (time < n) {
        time++;
        if (time % 2 == 1) { // detonate bomb on odd time slot
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].length(); j++) {
                    if (grid[i][j] != '2') {
                        continue;
                    }
                    if (i - 1 >= 0 && grid[i-1][j] != '2') {
                        grid[i-1][j] = '.';
                    }
                    if (i + 1 < grid.size() && grid[i+1][j] != '2') {
                        grid[i+1][j] = '.';
                    }
                    if (j - 1 >= 0 && grid[i][j-1] != '2') {
                        grid[i][j-1] = '.';
                    }
                    if (j + 1 < grid[0].length() && grid[i][j+1] != '2') {
                        grid[i][j+1] = '.';
                    }
                    grid[i][j] = '.';
                }
            }
            for (int i = 0; i < grid.size(); i++) { // increment timer
                replace(grid[i].begin(), grid[i].end(), '1', '2');
            }
        } else { // filling up empty slot with bomb on even time slot
            for (int i = 0; i < grid.size(); i++) {
                replace(grid[i].begin(), grid[i].end(), '.', '1');
            }
        }
    }
    // reverting state tracking character back to original character
    for (int i = 0; i < grid.size(); i++) {
        replace(grid[i].begin(), grid[i].end(), '1', 'O');
        replace(grid[i].begin(), grid[i].end(), '2', 'O');
        cout << grid[i] << endl;
    }
    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

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
