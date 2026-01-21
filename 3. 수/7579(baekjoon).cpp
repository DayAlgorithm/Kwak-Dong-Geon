#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m;
int memo[101], cost[101];
int dp[10001];

int main() {
    FastIO;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> memo[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
        sum += cost[i];
    }

    for (int i = 0; i < n; i++) {
        int mem = memo[i], c = cost[i];
        for (int j = sum; j >= c; j--) {
            dp[j] = max(dp[j], dp[j - c] + mem);
        }
    }

    for (int c = 0; c <= sum; c++) {
        if (dp[c] >= m) {
            cout << c;
            return 0;
        }
    }
    return 0;
}
