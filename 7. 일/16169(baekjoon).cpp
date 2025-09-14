#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
vector<vector<pair<int, int>>> arr;

long long dp[101][101];

int C = 0;

long long cnt(){
    for (int i = 1; i < C; ++i) {
        int next = i + 1;
        while(arr[next].empty() && next <= C) next++;
        if(next > C) break;
        
        for(auto& next_a : arr[next]) {
            long long max_time = 0;

            for(auto& a : arr[i]) {
                int idx = a.first;
                long long t = (long long)pow(abs(idx - next_a.first), 2);
                max_time = max(max_time, dp[i][idx] + t);
            }
            dp[next][next_a.first] = max_time + next_a.second;
        }
    }
    
    long long ret = 0;
    for(auto& a : arr[C]) {
        ret = max(ret, dp[C][a.first]);
    }
    
    return ret;
}

int main(){
    FastIO;
    cin >> n;
    arr.resize(n + 1);
    int c, t;
    for(int i = 1; i <= n; ++i){
        cin >> c >> t;
        arr[c].push_back({i, t});
        C = max(C, c);
    }
    
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            dp[i][j] = 0;
        }
    }
    
    for(auto& a : arr[1]){
        dp[1][a.first] = a.second;
    }
    
    cout << cnt() << "\n";
    
    return 0;
}