#include <bits/stdc++.h>

using namespace std;

int board[101][101];
int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    for(int i = 0; i < puddles.size(); ++i){
        dp[puddles[i][0]][puddles[i][1]] = -1;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 1 && j == 1) continue;
            if (dp[i][j] == -1){
                dp[i][j] = 0;
                continue;
            }
            if (i > 1 && dp[i - 1][j] != -1) {
                dp[i][j] += dp[i - 1][j] % 1000000007;
            }
            if (j > 1 && dp[i][j - 1] != -1) {
                dp[i][j] += dp[i][j - 1] % 1000000007;
            }
        }
    }
    return dp[m][n] % 1000000007;
}