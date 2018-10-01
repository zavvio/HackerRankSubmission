// https://www.hackerrank.com/challenges/bigger-is-greater
#include <bits/stdc++.h>
#include <algorithm>

/* chronicle order of how I figured out the steps
dhck
dhkc
dkch
dkhc
hcdk

dhck - c<k - swap(c,minLarger(right side[k])) - sort everything after pos(c)
dhkc - k>c,h<k - swap(h,minLarger(right side[k])) - sort everything after pos(h)

dkhc - h>c,k>h>,d<k - swap(d,minLarger(right side[h]) - sort everything after pos(d)
lmno - n<o - swap(n, minLarger(o) - sort after pos(n) - lmon
dcba - b>a,c>b,d>c - found == false - no answer
dcbb - b>=b,c>=b,d>=c - found == false - no answer
abdc - d>=c,b<d - found == true - swap(b, minLarger(c)) - sort after pos(b) - acbd
abcd - c<d - found == true - swap(c, minLarger(d)) - sort after pos(c) - abdc
*/

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    bool found = false;
    int pos, posMinLarger;
    char cLarger;
    // starting from end of char array, find first pair where left < right
    for (pos = w.length() - 2; pos > -1; pos--) {
        if (w[pos] < w[pos+1]) {
            found = true;
            break;
        }
    }
    if (found == false) {
        return "no answer";
    }
    cLarger = 'z' + 1; // arbitrary value larger than given char constraint
    // find the smallest char on the right side that is larger than that at found position
    for (int i = pos + 1; i < w.length(); i++) {
        if (w[i] > w[pos] && w[i] < cLarger) {
            posMinLarger = i;
            cLarger = w[i];
        }
    }
    // swap char at pos_found and pos_minLarger
    cLarger = w[pos];
    w[pos] = w[posMinLarger];
    w[posMinLarger] = cLarger;
    // sort everything right of pos_found alphabetically/small-to-large
    sort(w.begin() + pos + 1, w.end());
    return w;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
