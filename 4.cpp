#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> cache;

int tag(int i) {
    if (cache.find(i) != cache.end()) {
        return cache[i];
    }

    int result;
    if (i < 1) {
        throw "Tags >= 1";
    } else if ((i == 1) || (i == 2)) {
        result = 1;
    } else {
        result = tag(i - 1) + tag(i - 2);
    }

    cache[i] = result;
    return result;
}

int time_to_set_tags(int i) {
    int time = 0;
    for (int j = 1; j <= i; j++)
        time += tag(j);
    return time;
}   

int main() {
    int n;
    cin >> n;
    cout << time_to_set_tags(n) << endl;
    return 0;
}