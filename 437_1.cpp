#include <iostream>
#include <vector>

using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const vector<int>& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int sumRelGrid(vector<vector<int>> matrix, int n, int m, int s) {
    int sum = 0;
    for (int i = n; i < n + s; i++) {
        for (int j = m; j < m + s; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int max_s = 0, max_n = 0, max_m = 0;

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            if (grid[n][m] == 1) {
                for (int s = 1; s <= min(N - n, M - m); s++) {
                    if (sumRelGrid(grid, n, m, s) == s * s && s > max_s) {
                        max_s = s; max_n = n + 1; max_m = m + 1;
                    }
                }
            }
        }
    }

    printf("%d\n%d %d\n", max_s, max_n, max_m);
    return 0;
}
