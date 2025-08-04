#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int n, m, t, ans = INT_MAX;
int board[101][101];

bool flag;
int visited[101][101];
void bfs(){
    visited[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        if(y == n - 1 && x == m - 1){
            ans = min(ans, visited[y][x]);
        }
        for(int i = 0; i < 4; ++i){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < m && visited[ny][nx] == -1){
                if(board[ny][nx] == 2){
                    visited[ny][nx] = visited[y][x] + 1;
                    ans = min(ans, visited[ny][nx] + abs(n - 1 - ny) + abs(m - 1 - nx));
                }
                else if(!board[ny][nx]){
                    q.push({ny, nx});
                    visited[ny][nx] = visited[y][x] + 1;
                }
            }
        }
    }
}

int main(){
    FastIO;
    cin >> n >> m >> t;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> board[i][j];
        }
    }
    memset(visited, -1, sizeof(visited));
    bfs();
    if(ans > t) cout << "Fail";
    else cout << ans;
    return 0;
}