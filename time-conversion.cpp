// https://www.hackerrank.com/challenges/time-conversion
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string str) {
    int h, m, s;
    char half, result[9];
    sscanf(str.c_str(), "%d:%d:%d%c", &h, &m, &s, &half);
    if (half == 'A' && h == 12)
        h = 0;
    if (half == 'P' && h != 12)
        h += 12;
    sprintf(result, "%02d:%02d:%02d", h, m, s);
    return string(result);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
