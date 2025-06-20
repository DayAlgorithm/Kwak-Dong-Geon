#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int INF = INT_MAX;
int n, ans = INF;
string str;
int cache[2][2][51][51];

int dp(int start, int pre, int idx, int cnt){
    if(idx == n){
        if(str[n - 1] != '?'){
            if(str[n - 1] == 'H' && pre != start) return INF;
            if(str[n - 1] == 'L' && pre == start) return INF;
        }
        return cnt;
    }

    int &ret = cache[start][pre][idx][cnt];
    if(ret != -1) return ret;
    ret = INF;

    for(int i = 0; i <= 1; ++i){
        if(str[idx - 1] != '?'){
            if(str[idx - 1] == 'H' && pre != i) continue;
            if(str[idx - 1] == 'L' && pre == i) continue;
        }
        ret = min(ret, dp(start, i, idx + 1, cnt + i));
    }
    return ret;
}

int main() {
    FastIO;
    cin >> n >> str;
    ans = INF;
    memset(cache, -1, sizeof(cache));
    for(int i = 0; i <= 1; ++i){
        memset(cache, -1, sizeof(cache));
        ans = min(ans, dp(i, i, 1, i));
    }
    if(ans == INF) cout << -1;
    else cout << ans;
}