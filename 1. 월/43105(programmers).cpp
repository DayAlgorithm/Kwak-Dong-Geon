#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int dp[501][501];
    
    dp[0][0] = triangle[0][0];
    int n = triangle.size();
    int maxSum = 0;
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){
            dp[i][j] = max(dp[i - 1][j] + triangle[i][j], 
                           dp[i - 1][j - 1] + triangle[i][j]);
        }
        dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    }
    for(int i = 0; i < n; ++i){
        if(maxSum < dp[n - 1][i]) maxSum = dp[n - 1][i];
    }
    return maxSum;
}