#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int INF = -1e9;
const int dy[] = {0, 1, 0};
const int dx[] = {-1, 0, 1};

int n, m, mars[1001][1001];
vector<vector<vector<int>>> cache;

int dp(int y, int x, int dir) {
    if (y == n && x == m) return mars[y][x];

    int& ret = cache[y][x][dir];
    if (ret != INF) return ret;

    for(int i = 0; i < 3; ++i) {
        int ny = y + dy[i], nx = x + dx[i];

        if(ny < 1 || ny > n || nx < 1 || nx > m) continue;

        if(i == 0 && dir == 2) continue;
        if(i == 2 && dir == 0) continue;

        ret = max(ret, dp(ny, nx, i) + mars[y][x]);
    }
    return ret;
}

int main() {
    FastIO;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> mars[i][j];
        }
    }
        
    cache = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(m + 1, vector<int>(3, INF)));

    cout << dp(1, 1, 1);
    return 0;
}
