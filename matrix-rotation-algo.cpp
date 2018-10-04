// https://www.hackerrank.com/challenges/matrix-rotation-algo
#include <bits/stdc++.h>
#include <deque>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the matrixRotation function below.
/*  Approach:
    1. extract each layer out of the original matrix into a deque
    2. rotate elements from each layer (r mod size_of that layer) times
    3. update original matrix layer by layer from deque of each layer
    Note: using deque data structure because it can push/pop from both side,
          making life easier for rows other than first and last row.
*/
void matrixRotation(vector<vector<int>> matrix, int r) {
    int layer = min(matrix.size(), matrix[0].size()) / 2;
    deque<int> dq;
    vector<deque<int>> matrixLayered;
    for (int l = 0; l < layer; l++) {
        deque<int> v;
        for (int i = l; i < matrix.size() - l; i++) {
            if (i == l) {
                // first row of each layer
                for (int j = l; j < matrix[0].size() - l; j++) {
                    v.push_back(matrix[i][j]);
                }
            } else if (i == (matrix.size() - l - 1)) {
                // last row of each layer
                for (int j = matrix[0].size() - l - 1; j >= l ; j--) {
                    v.push_back(matrix[i][j]);
                }
            } else {
                // all other rows in-between
                dq.push_back(matrix[i][l]); // element on left edge
                v.push_back(matrix[i][matrix[0].size()-l-1]); // element on right edge
            }
        }
        // append the element on left edge to the deque in-order
        while (!dq.empty()) {
            v.push_back(dq.back());
            dq.pop_back();
        }
        // for (int x = 0; x < v.size(); x++) {
        //     cout << v[x] << " ";
        // }
        // cout << endl;
        matrixLayered.push_back(v);
    }
    // rotate layer-by-layer
    for (int l = 0; l < layer; l++) {
        int toRotate = r % matrixLayered[l].size();
        int buff;
        for (int i = 0; i < toRotate; i++) {
            buff = matrixLayered[l].front();
            matrixLayered[l].pop_front();
            matrixLayered[l].push_back(buff);
        }
    }
    // sync updated values back to original matrix
    for (int l = 0; l < layer; l++) {
        for (int i = l; i < matrix.size() - l; i++) {
            if (i == l) {
                // first row of each layer
                for (int j = l; j < matrix[0].size() - l; j++) {
                    matrix[i][j] = matrixLayered[l].front();
                    matrixLayered[l].pop_front();
                }
            } else if (i == (matrix.size() - l - 1)) {
                // last row of each layer
                for (int j = matrix[0].size() - l - 1; j >= l ; j--) {
                    matrix[i][j] = matrixLayered[l].front();
                    matrixLayered[l].pop_front();
                }
            } else {
                // all other rows in-between
                matrix[i][l] = matrixLayered[l].back(); // left edge gets last element
                matrixLayered[l].pop_back();
                matrix[i][matrix[0].size()-l-1] = matrixLayered[l].front(); // right edge
                matrixLayered[l].pop_front();
            }
        }
    }
    // output
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
