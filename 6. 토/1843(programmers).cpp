#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> arr){
    int size = arr.size() / 2 + 1, dp[101][101][2];
    
    for (int i = 0; i < size; i++) {
        int num = stoi(arr[2 * i]);
        dp[i][i][0] = num;
        dp[i][i][1] = num;
    }
    
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < size - i; j++) {
            int M = INT_MIN, n = INT_MAX;
            for (int k = 0; k < i; k++) {
                int maxNum, minNum;
                if (arr[2 * (j + k) + 1][0] == '-') {
                    maxNum = dp[j][j + k][0] - dp[j + k + 1][j + i][1];
                    minNum = dp[j][j + k][1] - dp[j + k + 1][j + i][0];
                }
                else {
                    maxNum = dp[j][j + k][0] + dp[j + k + 1][j + i][0];
                    minNum = dp[j][j + k][1] + dp[j + k + 1][j + i][1];
                }
                
                M = max(M, maxNum);
                n = min(n, minNum);
            }
            dp[j][j + i][0] = M;
            dp[j][j + i][1] = n;
        }
    }
    
    return dp[0][size - 1][0];
}