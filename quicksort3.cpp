// https://www.hackerrank.com/challenges/quicksort3
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void quickSort(vector<int> &arr, int smaller, int larger) {
    int i_S = smaller, i_L = smaller, p = arr[larger - 1];
    int tmp;
    if (smaller == larger) { // array of size 1 is sorted
        return;
    } else if (smaller + 1 == larger) { // array of size 2 need at most 1 swap
        if (arr[smaller] > arr[larger]) {
            swap(arr[smaller], arr[larger]);
        }
        return;
    }
    // cout << "sorting " << smaller << " to " << larger << endl;
    for (int i = i_S; i < larger - 1; i++) {
        if (arr[i] > p) {
            i_L++;
        } else {
            swap(arr[i_S], arr[i_L]);
            i_S++;
            i_L++;
        }
    }
    swap(arr[i_S], arr[larger - 1]); // swap pivot to "in-between"
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    quickSort(arr, smaller, i_S);
    quickSort(arr, i_S + 1, larger);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, tmp;
    vector<int> arr;
    cin >> n;
    while (n--) {
        cin >> tmp;
        arr.push_back(tmp);
    }
    quickSort(arr, 0, arr.size());
    return 0;
}
