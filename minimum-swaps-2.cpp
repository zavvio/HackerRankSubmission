// https://www.hackerrank.com/challenges/minimum-swaps-2
#include <bits/stdc++.h>
#include <map>

using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    /* Selection sort approach, too slow;
    Need to utilize property of this problem instead;
    i.e. natural number up to N, "1, 2, .., N"
         index 1 must be 1, index X must be X;
    Thus, use a "map[value] = index" data structure for O(1) access
      to directly retrieve & swap next number on the original array;
      then update the swapped number's index on the map. */

    // int temp, min, p_min, count_swap = 0;
    // for (int i = 0; i < arr.size(); i++) {
    //     min = arr[i];
    //     p_min = i;
    //     for (int j = i + 1; j < arr.size(); j++) {
    //         if (arr[j] < min) {
    //             min = arr[j];
    //             p_min = j;
    //         }
    //     }
    //     if (p_min != i) {
    //         temp = arr[i];
    //         arr[i] = arr[p_min];
    //         arr[p_min] = temp;
    //         count_swap++;
    //     }
    // }
    // return count_swap;
    int temp, count_swap = 0;
    map<int, int> index;
    for (int i = 0; i < arr.size(); i++) {
        index[arr[i]] = i;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != (i + 1)) {
            temp = arr[i];
            arr[i] = i + 1;
            arr[index[i+1]] = temp;
            index[temp] = index[i+1];
            count_swap++;
        }
    }
    return count_swap;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

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
