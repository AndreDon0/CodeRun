#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N + 1, vector<int>(M + 1));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    
    for (int i = 0; i < N + 1; i++) {
        grid[i][M] = 0;
    }

    for (int j = 0; j < M; j++) {
        grid[N][j] = 0;
    }

    int max_s = 0, max_n = 0, max_m = 0;

    for (int s = 1; s <= min(N, M); s++) {
        for (int i = 0; i <= N - s; i++) {
            for (int j = 0; j <= M - s; j++) {
                if (grid[i][j] == 1) {
                    max_s = s; max_n = i, max_m = j;
                    if ((grid[i + 1][j] == 1) && (grid[i][j + 1] == 1) && (grid[i + 1][j + 1] == 1)) {
                        grid[i][j] = 1;
                    } else {
                        grid[i][j] = 0;
                    }
                } else {
                    grid[i][j] = 0;
                }
            }
        }
    }

    printf("%d\n%d %d\n", max_s, max_n + 1, max_m + 1);
    return 0;
}
