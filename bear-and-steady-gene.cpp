// https://www.hackerrank.com/challenges/bear-and-steady-gene
#include <bits/stdc++.h>
#include <map>

using namespace std;

bool isSteady(map<char, int> &count, int n) {
    // Make sure all the remaining char outside of the substring is under the N / 4 limit
    if (count['A'] <= n && count['T'] <= n && count['G'] <= n && count['C'] <= n) {
        return true;
    }
    return false;
}

// Complete the steadyGene function below.
int steadyGene(string gene) {
    int left = 0, right = 0, minLen = INT_MAX, len = gene.length() / 4;
    map<char, int> count;
    count['A'] = 0;
    count['T'] = 0;
    count['G'] = 0;
    count['C'] = 0;
    // First count occurance of each char
    for (char c : gene) {
        count[c]++;
    }
    // starting before 0, we stretch the sliding window
    while (left < gene.length() && right < gene.length()) {
        if (!isSteady(count, len)) {
            // if, outside the target substring, any 1 of the 4 has higher count than N / 4
            // we expand the window toward right by one, putting that into the substring
            count[gene[right]]--;
            right++;
        } else {
            // if the outside string is "safe", all under N / 4, we got a legit window
            // update record if this new window is the smallest ever
            minLen = min(minLen, right - left);
            // slide/shrink the window to the right by shifting left bound of substring
            count[gene[left]]++;
            left++;

            // note: for the new char that got kicked out on the left,
            //       if it's one of those insufficient char, next while loop check will
            //       still be steady because the count will still remain under N / 4,
            //       then we keep poping char out on left side, shrinking the window;
            //       if it's actually one of the exceed N / 4 ones,
            //       we need to resume expansion on the right bound of the window

            // note2: reason why we don't move the right bound back to just after
            //        left bound when left bound increases is because
            //        the char right before right bound will always be one that make
            //        the outside string non steady, we previously moved the right bound
            //        over it because it's an extra char that makes one char exceed N/4;
            //        so it doesn't matter what happens on left bound side,
            //        we don't need to restart the right bound hunting
        }
    }
    return minLen;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string gene;
    getline(cin, gene);

    int result = steadyGene(gene);

    fout << result << "\n";

    fout.close();

    return 0;
}
