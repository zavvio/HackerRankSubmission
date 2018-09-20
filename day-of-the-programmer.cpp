// https://www.hackerrank.com/challenges/day-of-the-programmer
#include <bits/stdc++.h>

using namespace std;

// Complete the solve function below.
string solve(int year) {
    bool leap = false;
    string str_leap = "12.09.", str_reg = "13.09.";
    if (year == 1918) {
        return "26.09.1918";
    } else if (year < 1918) {
        if (year % 4 == 0)
            return str_leap + to_string(year);
        else
            return str_reg + to_string(year);
    } else {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return str_leap + to_string(year);
        else
            return str_reg + to_string(year);
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int year;
    cin >> year;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = solve(year);

    fout << result << "\n";

    fout.close();

    return 0;
}
