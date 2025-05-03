#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int n, m; 
int board[1001][1001];

int visited[1001][1001];
queue<pair<int, int>> q;
void bfs(int startY, int startX){
    q.push({startY, startX});
    visited[startY][startX] = 0;
    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < m 
                && board[ny][nx] && visited[ny][nx] == -1){
                    visited[ny][nx] = visited[y][x] + 1;
                    q.push({ny, nx});
            } 
        }
    }
}

int main() {
    FastIO;
    cin >> n >> m;
    int y, x;   //목표지점 좌표표
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] == 2){
                y = i;
                x = j;
            }
        }
    }
    memset(visited, -1, sizeof(visited));
    bfs(y, x);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(visited[i][j] == -1){    //가지 못한 땅
                if(board[i][j]) cout << -1 << " ";  //갈 수 있는데 막힌 경우
                else cout << 0 << " ";  //원래 못가는 땅
            }
            else cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}