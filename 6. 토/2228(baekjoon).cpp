#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = 1e9;
int n, m;
vector<int> num;

vector<vector<int>> cache;
int dp(int idx, int cnt){
    if (cnt == 0) return 0;
    if (idx >= n) return -INF;

    int& ret = cache[idx][cnt];
    if (ret != -1) return ret;

    int sum = 0;
    ret = dp(idx + 1, cnt);
    for (int i = idx; i < n; ++i){
        sum += num[i];
        ret = max(ret, dp(i + 2, cnt - 1) + sum);
    }
    return ret;
}

int main() {
    FastIO;
    cin >> n >> m;
    num = vector<int>(n + 1);
    for(int i = 0; i < n; ++i){
        cin >> num[i];
    }
    cache = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
    cout << dp(0, m);
    return 0;
}
