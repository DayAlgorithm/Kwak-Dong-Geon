#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, k;
int board[105][105];
bool visited[105][105];

int main() {
    FastIO;
    cin >> n >> m >> k;

    for(int i = 0; i < k; i++){
        int r, c;
        cin >> r >> c;
        board[r][c] = 1;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(board[i][j] == 1 && !visited[i][j]) {
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                int s = 0;

                while(!q.empty()){
                    pair<int, int> cur = q.front();
                    q.pop();
                    s++;

                    for(int d = 0; d < 4; d++) {
                        int nx = cur.first + dx[d], ny = cur.second + dy[d];

                        if(nx < 1 || ny < 1 || nx > n || ny > m) continue;

                        if(board[nx][ny] == 1 && !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
                if(s > ans) ans = s;
            }
        }
    }

    cout << ans;

    return 0;
}