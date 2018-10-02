// https://www.hackerrank.com/challenges/larrys-array
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the larrysArray function below.
/*
    General solution is to classify the array into two portion:
        sorted in the front and unsorted at the back;
    keep swapping the next-smallest number to the front of the unsorted portion of the array;
    For swapping, there are two conditions:
        1. there are 2 numbers in front of the next-smallest number which are bigger;
           i.e. for number A, B, C: C is the smallest number to be swapped to front
        2. only one number in front is larger than next-smallest number;
           i.e. for number A, B, C: B is the smallest number to be swapped to front
        3. all other cases mean no swap is possible, possibly not enough number to swap
    Early discovery of no-swap-possible yield NO earlier;
    otherwise, at the end of the sort, manually check the last two numbers for
    whether they are in sorted order or not.
*/
string larrysArray(vector<int> A) {
    bool invalid;
    int min, index_min, buff;
    // attempt to sort all 3-number slots
    for (int index_sorted = 0; index_sorted < A.size() - 2; index_sorted++) {
        // First, find the smallest number in unsorted portion of array
        min = A[index_sorted];
        index_min = index_sorted;
        for (int i = index_sorted + 1; i < A.size(); i++) {
            if (A[i] < min) {
                min = A[i];
                index_min = i;
            }
        }
        cout << "index_sorted = " << index_sorted << ", index_min = " << index_min << endl;
        // is smallest number already in the front of unsorted portion?
        if (index_sorted == index_min) {
            continue;
        }
        // move smallest number to front
        while (index_sorted != index_min) {
            if (index_min - 2 > -1 && A[index_min - 2] > A[index_min]) {
                // For A,B,C: C is the smallest number
                cout << "Case 1 swap\n";
                buff = A[index_min];
                A[index_min] = A[index_min - 1];
                A[index_min - 1] = A[index_min - 2];
                A[index_min - 2] = buff;
                index_min -= 2;
            } else if (index_min + 1 < A.size()) {
                // For A,B,C: B is the smallest number
                cout << "Case 2 swap\n";
                buff = A[index_min - 1];
                A[index_min - 1] = A[index_min];
                A[index_min] = A[index_min + 1];
                A[index_min + 1] = buff;
                index_min -= 1;
            } else {
                cout << "cannot swap\n";
                break;
            }
        }
        // DEBUG ONLY: print the current array
        for (int x = 0; x < A.size(); x++) {
            cout << A[x] << " ";
        }
        cout << endl;
        // early discovery of no-swap-possible
        if (index_sorted != index_min) {
            return "NO";
        }
    }
    // manual check of last two numbers to be in sorted order or not
    for (int i = A.size() - 2; i < A.size() - 1; i++) {
        if (A[i] > A[i + 1]) {
            return "NO";
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string A_temp_temp;
        getline(cin, A_temp_temp);

        vector<string> A_temp = split_string(A_temp_temp);

        vector<int> A(n);

        for (int i = 0; i < n; i++) {
            int A_item = stoi(A_temp[i]);

            A[i] = A_item;
        }

        string result = larrysArray(A);

        fout << result << "\n";
    }

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
