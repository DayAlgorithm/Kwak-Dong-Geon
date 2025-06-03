#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int t, n;

int cache[2001][2001];
int dp(int now, int idx){
    if(now == n) return 1;
    if(idx + now > n) return 0;

    int& ret = cache[now][idx];
    if(ret != -1) return ret;
    ret = 0;
    
    ret += dp(now, idx + 1) + dp(now + idx, idx + 1);
    ret %= 100999;
    return ret;
}

int main(){
    FastIO;
    cin >> t;
    while(t--){
        cin >> n;
        memset(cache, -1, sizeof(cache));
        cout << dp(0, 1) << "\n";
    }
    return 0;
}