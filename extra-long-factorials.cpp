// https://www.hackerrank.com/challenges/extra-long-factorials
#include <bits/stdc++.h>

using namespace std;

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    vector<int> bigInt;
    bigInt.push_back(1);
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < bigInt.size(); j++) {
            bigInt[j] *= i;
        }
        for (int j = 0; j < bigInt.size(); j++) {
            if (bigInt[j] / 10 > 0) {
                if (j == (bigInt.size() - 1)) {
                    bigInt.push_back(0);
                }
                bigInt[j+1] = bigInt[j+1] + bigInt[j] / 10;
                bigInt[j] = bigInt[j] % 10;
            }
        }
    }
    for (int i = bigInt.size() - 1; i > -1; i--) {
        cout << bigInt[i];
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
