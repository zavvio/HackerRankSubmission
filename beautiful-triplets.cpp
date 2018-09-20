// https://www.hackerrank.com/challenges/beautiful-triplets
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the beautifulTriplets function below.
int beautifulTriplets(int d, int arr[], int n) {
    int count = 0, count1, count2;
    for (int i = 0; i < n - 2; i++) {
        count1 = 0;
        count2 = 0;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == arr[i] + d) {
                count1++;
            }
            if (arr[j] == arr[i] + 2 * d) {
                count2++;
            }
        }
        count = count + count1 * count2;
    }
    return count;
}

int main()
{
    int n, d;
    cin >> n >> d;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = beautifulTriplets(d, arr, n);
    cout << result << endl;
    return 0;
}
