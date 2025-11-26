#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int t;
int n, m;
int value[21];
int dp[10001];

int main() {
    FastIO;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> value[i];
        }
        cin >> m;
        fill(dp, dp + m + 1, 0);
        dp[0] = 1;

        for(int i = 0; i < n; i++){
            for(int j = value[i]; j <= m; j++){
                dp[j] += dp[j - value[i]];
            }
        }

        cout << dp[m] << "\n";
    }
    return 0;
}