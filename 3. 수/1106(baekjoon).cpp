#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int c, n;
int dp[100001];
vector<pair<int, int>> ads;

int main() {
    FastIO;
    cin >> c >> n;
    ads.resize(n);
    
    int maxCustomer = 0;
    for(int i = 0; i < n; ++i){
        int w, v;
        cin >> w >> v;
        ads[i] = {w, v};
        maxCustomer = max(maxCustomer, v);
    }
    
    int limit = c + maxCustomer;
    for(int i = 1; i <= limit; ++i) dp[i] = INT_MAX;
    dp[0] = 0;

    for(int i = 1; i <= limit; ++i){
        for(int j = 0; j < n; ++j){
            int w = ads[j].first, v = ads[j].second;
            if(i - v >= 0 && dp[i - v] != INT_MAX)
                dp[i] = min(dp[i], dp[i - v] + w);
        }
    }
    
    int ans = INT_MAX;
    for(int i = c; i <= limit; ++i){
        ans = min(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
