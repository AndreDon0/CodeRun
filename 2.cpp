#include <iostream>
using namespace std;

string isTrianglePossible(int side1, int side2, int side3) {
    if ((side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1)) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int side1, side2, side3;

    cin >> side1 >> side2 >> side3;

    string result = isTrianglePossible(side1, side2, side3);
    cout << result << endl;

    return 0;
}
