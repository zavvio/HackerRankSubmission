// https://www.hackerrank.com/challenges/strange-advertising
#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
    int shared = 5, cumulate = 0, liked;
    for (int i = 0; i < n; i++) {
        liked = floor(shared / 2);
        cumulate += liked;
        shared = liked * 3;
    }
    return cumulate;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
