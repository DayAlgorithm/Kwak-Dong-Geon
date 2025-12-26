#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;


int n;
vector<int> boxs;
vector<int> dp;


int main() {
    FastIO;
    cin >> n;
    boxs.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> boxs[i];
    }
    
    dp.resize(n, 1);
    int ans = 1;
    
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(boxs[j] < boxs[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    
    cout << ans;
    
    return 0;
}
