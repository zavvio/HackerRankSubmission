// https://www.hackerrank.com/challenges/palindrome-index
// Test case: hgygsvlfcwnswtuhmyaljkqlqjjqlqkjlaymhutwsnwcwflvsgygh (remove 44)

#include <bits/stdc++.h>

using namespace std;

// Complete the palindromeIndex function below.
int palindromeIndex(string s) {
    bool removed = false;
    int remove = -1, front = -1, back = s.length();
    while (front < back) {
        front++;
        back--;
        if (s[front] == s[back]) {
            continue;
        }
        if (removed) { // more than one char not matching
            return -1;
        }
        if (front + 1 == back) { // last pair, just remove any one
            return front;
        }
        // determine to remove front or back, need to check at least 2 char pairs
        if (s[front + 1] == s[back] && s[front + 2] == s[back - 1]) {
            remove = front;
            front++;
            removed = true;
        } else if (s[front] == s[back - 1] && s[front + 1] == s[back - 2]) {
            remove = back;
            back--;
            removed = true;
        } else { // unexpected exception
            cout << "special case: " << s[front] << "-" << front << ", " << s[back] << "-" << back << endl;
        }
    }
    return remove;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
