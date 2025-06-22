#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int dy[] = {0, 0, 0, 1, -1};
const int dx[] = {0, 1, -1, 0, 0};

int n, m, k, ans = INT_MAX;
int board[1001][1001];

int visited[1001][1001][11][2];
void bfs(){
    queue<tuple<int, int, int, bool>> q;
    q.push(make_tuple(0, 0, k, true));
    visited[0][0][k][1] = 1;
    while(!q.empty()){
        int y = get<0>(q.front()), x = get<1>(q.front()), K = get<2>(q.front());
        bool t = get<3>(q.front());
        q.pop();
        if(y == n - 1 && x == m - 1){
            ans = min(ans, visited[y][x][K][t]);
            return;
        }

        for(int i = 0; i < 5; ++i){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny >= n || nx >= m || ny < 0 || nx < 0 || visited[ny][nx][K][!t]) continue;
            if(!i){
                q.push(make_tuple(ny, nx, K, !t));
                visited[ny][nx][K][!t] = visited[y][x][K][t] + 1;
                continue;
            }
            if(!board[ny][nx]){
                q.push(make_tuple(ny, nx, K, !t));
                visited[ny][nx][K][!t] = visited[y][x][K][t] + 1;
            }
            else if(t && K && !visited[ny][nx][K - 1][!t]){
                q.push(make_tuple(ny, nx, K - 1, !t));
                visited[ny][nx][K - 1][!t] = visited[y][x][K][t] + 1;
            }
        }
    }
}

int main(){
    FastIO;
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i){
        string str;
        cin >> str;
        for(int j = 0; j < m; ++j){
            board[i][j] = str[j] - '0';
        }
    }
    bfs();
    if(ans == INT_MAX) cout << -1;
    else cout  << ans;
    return 0;
}