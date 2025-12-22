#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m;
vector<string> board;
bool visited[55][55];
bool found = false;

void dfs(int sx, int sy, int x, int y, int d) {
    if(found) return;

    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (board[nx][ny] != board[sx][sy]) continue;

        if(!visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(sx, sy, nx, ny, d + 1);
            visited[nx][ny] = false;
        } else {
            if(nx == sx && ny == sy && d + 1 >= 4) {
                found = true;
                return;
            }
        }
        if(found) return;
    }
}

int main() {
    FastIO;

    cin >> n >> m;
    board.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            memset(visited, false, sizeof(visited));
            visited[i][j] = true;
            dfs(i, j, i, j, 1);
            if(found) {
                cout << "Yes\n";
                return 0;
            }
        }
    }

    cout << "No\n";
    return 0;
}
