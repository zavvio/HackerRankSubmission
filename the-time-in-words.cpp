// https://www.hackerrank.com/challenges/the-time-in-words
#include <bits/stdc++.h>

using namespace std;

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
    vector<string> hours = {
        "", "one", "two", "three", "four", "five", "six",
        "seven", "eight", "nine", "ten", "eleven", "twelve",
        "thirteen", "fourteen", "", "sixteen", "seventeen", "eighteen",
        "nineteen", "twenty", "twenty one", "twenty two", "twenty three",
        "twenty four", "twenty five", "twenty six", "twenty seven",
        "twenty eight", "twenty nine"
    };
    string buff, hour;
    if (m > 30) {
        h++;
        if (h > 12) {
            h %= 12;
        }
    }
    if (m == 0) {
        return hours[h] + " o' clock";
    } else if (m == 15) {
        return "quarter past " + hours[h];
    } else if (m == 30) {
        return "half past " + hours[h];
    } else if (m == 45) {
        return "quarter to " + hours[h];
    }
    if (m < 30) {
        buff = hours[m];
    } else {
        buff = hours[60 - m];
    }
    buff += m == 1 ? " minute" : " minutes";
    buff += m < 30 ? " past " : " to ";
    buff += hours[h];
    return buff;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}
