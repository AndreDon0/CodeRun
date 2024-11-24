#include <iostream>
#include <vector>
using namespace std;

int neigbours_numbers(vector<int> V) {
    if (V.size() < 3)
        return 0;
    else {
        int n = 0;
        for (int i = 1; i < V.size() - 1; i++) {
            if ((V[i - 1] < V[i]) && (V[i] > V[i + 1]))
                n++;
        }
        return n;
    }
}

int main() {

    vector<int> arr;
    int input;
	while (cin >> input)
        arr.push_back(input);

    cout << neigbours_numbers(arr) << endl;

    return 0;
}