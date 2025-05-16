#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n, m, ans;
vector<int> use;

int cache[21][21][21];
int dp(int a, int b, int cnt){
    if(cnt == m) return 0;

    int& ret = cache[a][b][cnt];
    if(ret != -1) return ret;

    ret = min(abs(a - use[cnt]) + dp(use[cnt], b, cnt + 1), abs(b - use[cnt]) + dp(a, use[cnt], cnt + 1));
    return ret;
}

int main(){
    FastIO;
    cin >> n;
    int a, b;
    cin >> a >> b;
    cin >> m;
    use = vector<int>(m);
    for(int i = 0; i < m; ++i){
        cin >> use[i];
    }
    memset(cache, -1, sizeof(cache));
    cout << dp(a, b, 0);
    return 0;
}