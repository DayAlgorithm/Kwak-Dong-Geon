#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;
int ice[301][301], next_ice[301][301];
bool visited[301][301];

int cnt_sea(int x, int y) {
    int cnt = 0;
    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && ice[nx][ny] == 0) cnt++;
    }
    return cnt;
}

void bfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(ice[nx][ny] == 0) continue;
            if(!visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    FastIO;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> ice[i][j];
        }
    }

    int ans = 0;
    while(true) {
        memset(visited, 0, sizeof(visited));
        int land = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(ice[i][j] && !visited[i][j]) {
                    bfs(i, j);
                    land++;
                }
            }
        }
        if(land >= 2) {
            cout << ans;
            return 0;
        }
        if(land == 0) {
            cout << 0;
            return 0;
        }
        memset(next_ice, 0, sizeof(next_ice));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(ice[i][j]) {
                    int sea = cnt_sea(i, j);
                    next_ice[i][j] = max(0, ice[i][j] - sea);
                }
            }
        }
        memcpy(ice, next_ice, sizeof(ice));
        ans++;
    }
    return 0;
}
