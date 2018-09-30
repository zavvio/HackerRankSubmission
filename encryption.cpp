// https://www.hackerrank.com/challenges/encryption
#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    string encrypted;
    int row, col, buff;
    s.erase(remove(s.begin(), s.end(), ' '), s.end()); // remove spaces
    row = floor(sqrt((double) s.length()));
    col = ceil(sqrt((double) s.length()));
    if (row * col < s.length()) { // ensure enough space
        row++;
    }
    // cout << s.length() << ", " << sqrt((double) s.length()) << ", " << row << ", " << col << endl;
    char grid[row][col];
    for (int i = 0; i < s.length(); i++) { // fill in original content
        grid[i/col][i%col] = s[i];
    }
    buff = s.length();
    while (buff < row * col) { // fill in extra character
        grid[buff/col][buff%col] = '\0';
        buff++;
    }
    // Printing the filled grid
    // for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < col; j++) {
    //         cout << grid[i][j];
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < col; i++) { // traverse grid the "mirrored" way
        for (int j = 0; j < row; j++) {
            if (grid[j][i] == '\0') {
                break;
            }
            encrypted.push_back(grid[j][i]);
        }
        encrypted.push_back(' ');
    }
    return encrypted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
