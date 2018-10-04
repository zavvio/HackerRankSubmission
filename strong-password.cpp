// https://www.hackerrank.com/challenges/strong-password
#include <bits/stdc++.h>
#include <string>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    bool hasSix = false, hasDigit = false;
    bool hasLowerCase = false, hasUpperCase = false, hasSpecialChar = false;
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";
    int count = 4;

    if (password.length() > 5) {
        hasSix = true;
    }
    for (char c : password) {
        if (!hasDigit) {
            if (numbers.find(c) != string::npos) {
                hasDigit = true;
                count--;
            }
        }
        if (!hasLowerCase) {
            if (lower_case.find(c) != string::npos) {
                hasLowerCase = true;
                count--;
            }
        }
        if (!hasUpperCase) {
            if (upper_case.find(c) != string::npos) {
                hasUpperCase = true;
                count--;
            }
        }
        if (!hasSpecialChar) {
            if (special_characters.find(c) != string::npos) {
                hasSpecialChar = true;
                count--;
            }
        }
        if (count == 0) {
            break;
        }
    }
    if (hasSix) {
        return count;
    } else {
        return max(6 - (int) password.length(), count);
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
