// https://www.hackerrank.com/challenges/almost-sorted
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {
    int first = -1, last = -1, tmp;
    bool sorted;
    // find the first unsorted element
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            first = i;
            break;
        }
    }
    // if no unsorted element found, it's sorted
    if (first == -1) {
        cout << "yes" << endl;
        return;
    }
    // find the "last" unsorted element, in other word, just before the first sorted element after all the unsorted ones
    for (int i = first + 1; i < arr.size(); i++) {
        if (arr[i] >= arr[first]) {
            last = i - 1;
            break;
        }
    }
    // if last is not overwritten, it must be the last element of the array
    if (last == -1) {
        last = arr.size() - 1;
    }
    // check whether the portion of the array after the "last" unsorted element is sorted
    for (int i = last + 1; i < arr.size() - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            cout << "no" << endl;
            return;
        }
    }
    // do the swap
    tmp = arr[first];
    arr[first] = arr[last];
    arr[last] = tmp;
    sorted = true;
    // check entire array after swapped
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            sorted = false;
            break;
        }
    }
    if (sorted) {
        cout << "yes" << endl;
        cout << "swap " << first + 1 << " " << last + 1 << endl;
        return;
    }
    tmp = arr[first];
    arr[first] = arr[last];
    arr[last] = tmp;
    // if we reverse, will the head element be smaller than the one before "first"?
    if (first - 1 >= 0 && arr[last] < arr[first - 1]) {
        cout << "no" << endl;
        return;
    }
    // check whether the unsorted portion before first and last is sorted reversely
    sorted = true;
    for (int i = first; i < last; i++) {
        if (arr[i] < arr[i + 1]) {
            sorted = false;
            break;
        }
    }
    if (sorted) {
        cout << "yes" << endl;
        cout << "reverse " << first + 1 << " " << last + 1 << endl;
    } else {
        cout << "no" << endl;
    }
}

int main()
{
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

    almostSorted(arr);

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
