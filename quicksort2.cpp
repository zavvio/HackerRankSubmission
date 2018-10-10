// https://www.hackerrank.com/challenges/quicksort2
#include <bits/stdc++.h>
using namespace std;

void partition(vector<int> &arr, vector<int> &left, vector<int> &eq, vector<int> &right) {
    int p = arr[0];
    for (int i : arr) {
        if (i < p) {
            left.push_back(i);
        } else if (i > p) {
            right.push_back(i);
        } else {
            eq.push_back(i);
        }
    }
}

void quickSort(vector <int> &arr) {
	// Complete this function
    int p;
    vector<int> left, eq, right;
    if (arr.size() < 2) {
        return;
    } else if (arr.size() == 2) {
        if (arr[0] > arr[1]) {
            p = arr[0];
            arr[0] = arr[1];
            arr[1] = p;
        }
        cout << arr[0] << " " << arr[1] << endl;
        return;
    } else {
        partition(arr, left, eq, right);
        // cout << "left: ";
        // for (int i : left) {
        //     cout << i << " ";
        // }
        // cout << "eq: ";
        // for (int i : eq) {
        //     cout << i << " ";
        // }
        // cout << "right: ";
        // for (int i : right) {
        //     cout << i << " ";
        // }
        // cout << endl;
        quickSort(left);
        quickSort(right);
        arr.clear();
        for (int i : left) {
            arr.push_back(i);
            cout << i << " ";
        }
        for (int i : eq) {
            arr.push_back(i);
            cout << i << " ";
        }
        for (int i : right) {
            arr.push_back(i);
            cout << i << " ";
        }
        cout << endl;
    }
}


int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}
