// https://www.hackerrank.com/challenges/bon-appetit
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k, tmp, sum = 0;
    double charged;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (i != k)
            sum += tmp;
    }
    cin >> charged;
    if (charged != (double) sum / 2) {
        cout << trunc(charged - (double) sum / 2) << endl;
    } else
        cout << "Bon Appetit\n";
    return 0;
}
