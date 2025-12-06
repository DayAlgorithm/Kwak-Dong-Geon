#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m;
vector<vector<int>> maze;

int cache[1001][1001];
int dp(int r, int c){
    if(r == n - 1 && c == m - 1) return maze[r][c];
    if(r >= n || c >= m) return -INT_MAX;

    int& ret = cache[r][c];
    if(ret != -1) return ret;

    ret = max({dp(r + 1, c), dp(r, c + 1), dp(r + 1, c + 1)}) + maze[r][c];
    return ret;
}


int main() {
    FastIO;
    cin >> n >> m;
    maze.resize(n, vector<int>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> maze[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    cout << dp(0, 0);
    return 0;
}