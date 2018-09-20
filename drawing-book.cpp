// https://www.hackerrank.com/challenges/drawing-book
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
    int front, back;
    // front = trunc((double) p / 2);
    // back = round((double) (n - p) / 2);
    // if (n % 2 != 0 && n != p) back--;
    front = p / 2;
    if (n % 2 == 0)
        back = round((double) (n - p) / 2);
    else
        back = trunc((double) (n - p) / 2);
    return front < back ? front : back;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}
