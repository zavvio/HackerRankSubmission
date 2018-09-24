// https://www.hackerrank.com/challenges/two-pluses
/*
14 14
GGGGGGGGGGGGGG
GGBBBBGBBBBBGG
GGBBBBGBBBBBGG
GGBBBBGBBBBBGG
GGGGGGGGGGGGGG
GGGGGGGGGGGGGG
GGGGGGGGGGGGGG
GGGGGGGGGGGGGG
GGBBBBGBBBBBGG
GGBBBBGBBBBBGG
GGGGGGGGGGGGGG
GGBBBBGBBBBBGG
GGBBBBGBBBBBGG
GGGGGGGGGGGGGG
*/
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool isOverlap(int x1, int y1, int offset1, int x2, int y2, int offset2) {
    int diffX = abs(x1 - x2);
    int diffY = abs(y1 - y2);
    if (x1 == x2 && diffY <= offset1 + offset2) {
        return true;
    }
    if (y1 == y2 && diffX <= offset1 + offset2) {
        return true;
    }
    if ((diffX <= offset1 && diffY <= offset2) ||
        (diffY <= offset1 && diffX <= offset2)) {
        return true;
    }
    return false;
}

// Complete the twoPluses function below.
int twoPluses(vector<string> grid) {
    int count[grid.size()][grid[0].length()] = {0, 0, 0, 0, 0, 0, 0};
    int product[grid.size()][grid[0].length()] = {0, 0, 0, 0, 0, 0, 0};
    int offset, max, one = 0, two = 0;
    int offset1, offset2;
    int diffX, diffY;
    bool overlap;
    // First, calculate the max tier of plus can each cell has
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].length(); j++) {
            offset = 0;
            count[i][j] = 0;
            // expanding layer and check each direction
            while ((i - offset >= 0) && (i + offset < grid.size())
                   && (j - offset >= 0) && (j + offset < grid[0].length())) {
                if (grid[i-offset][j] != 'G') {
                    break;
                }
                if (grid[i+offset][j] != 'G') {
                    break;
                }
                if (grid[i][j-offset] != 'G') {
                    break;
                }
                if (grid[i][j+offset] != 'G') {
                    break;
                }
                count[i][j]++;
                offset++;
            }
            cout << count[i][j] << " ";
        }
        cout << endl;
    }
    // for each cell, loop through the entire grid to find its max plus companion
    max = 0;
    for (int i1 = 0; i1 < grid.size(); i1++) {
        for (int j1 = 0; j1 < grid[0].length(); j1++) {
            // minor speed up bypass if current cell has no plus
            if (count[i1][j1] == 0) {
                continue;
            }
            // cout << "Finding max product for cell i1 = " << i1 << ", j1 = " << j1 << endl;
            for (int i2 = 0; i2 < grid.size(); i2++) {
                for (int j2 = 0; j2 < grid[0].length(); j2++) {
                    overlap = false;
                    offset1 = count[i1][j1] - 1;
                    offset2 = count[i2][j2] - 1;
                    // minor speed up bypass if to-be-compared cell has no plus
                    if (offset2 == -1) {
                        continue;
                    }
                    // problem requirement: two plus cannot overlap
                    overlap = isOverlap(i1, j1, offset1, i2, j2, offset2);
                    // in case of overlap, try downsizing the larger plus voluntarily because it's not necessary to always use the maximum size of that particular cell
                    while (overlap == true && (offset1 > 0 || offset2 > 0)) {
                        overlap = false;
                        // downsize the larger one because for (6x4) --> (5x4) > (6x3)
                        if (offset1 > offset2) {
                            offset1--;
                        } else {
                            offset2--;
                        }
                        overlap = isOverlap(i1, j1, offset1, i2, j2, offset2);
                    }
                    // calculate the actual product once two non-overlap plus are found
                    if (overlap == false) {
                        one = offset1 * 4 + 1;
                        two = offset2 * 4 + 1;
                        if (one * two > max) { // is the product the largest?
                            max = one * two;
                            cout << "new max >> i1 = " << i1 << ", j1 = " << j1 << ", i2 = " << i2 << ", j2 = " << j2 << ", offset1 = " << offset1 << ", offset2 = " << offset2 << endl;
                        }
                    }
                    // cout << "calculating 2nd cell i2 = " << i2 << ", j2 = " << j2 << ", overlap = " << overlap << ", offset1 = " << offset1 << ", offset2 = " << offset2 << endl;
                }
            }
        }
    }
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    int result = twoPluses(grid);

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
