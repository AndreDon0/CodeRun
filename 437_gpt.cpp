#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Input grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    int maxSize = 0;
    int topLeftX = -1, topLeftY = -1;

    // Fill the DP table
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 1) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1; // Edge cells
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                // Update maximum square size
                if (dp[i][j] > maxSize) {
                    maxSize = dp[i][j];
                    topLeftX = i - maxSize + 1;
                    topLeftY = j - maxSize + 1;
                }
            }
        }
    }

    // Output the result
    cout << maxSize << " " << topLeftX + 1 << " " << topLeftY + 1 << endl;

    return 0;
}
