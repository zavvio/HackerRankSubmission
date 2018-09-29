// https://www.hackerrank.com/challenges/organizing-containers-of-balls
#include <bits/stdc++.h>
#include <algorithm>
/*
10
2
1 0
0 1
2
1 2
2 1
3
0 4 0
2 0 1
1 0 2
4
1 2 3 4
2 1 4 3
3 4 2 1
4 3 1 2
4
0 0 5 0
4 0 0 0
0 2 0 1
0 1 0 2
2
2 1
0 0
2
2 1
0 1
3
1 2 3
3 2 1
2 3 1
3
1 0 0
0 2 0
0 2 0
4
1 2 1 3
2 1 3 1
1 3 2 1
3 2 1 1

Possible
Possible
Possible
Possible
Possible
Impossible
Impossible
Impossible
Impossible
Impossible
*/
using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    // Hint: type 0 ball not necessary be in container 0
    // Hint: number of balls in each container will always stay the same
    // Hint: assume there is solution, for each type of ball, there must be a container with total number of balls in that container equals the total number of that specific type of ball
    int bucket[container.size()] = {0}, type[container.size()] = {0};
    for (int i = 0; i < container.size(); i++) {
        for (int j = 0; j < container.size(); j++) {
            bucket[i] += container[i][j]; // count total number of balls in each container
            type[j] += container[i][j]; // count total number of each type of ball
        }
    }
    // sort them for easy comparison
    sort(bucket, bucket + container.size());
    sort(type, type + container.size());
    for (int i = 0; i < container.size(); i++) {
        if (bucket[i] != type[i]) {
            return "Impossible";
        }
    }
    return "Possible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
