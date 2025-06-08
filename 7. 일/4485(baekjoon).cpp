#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int n, cnt = 1, board[126][126];

int visited[126][126];
void bfs(){
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = board[0][0];

    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[y][x] + board[ny][nx] >= visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + board[ny][nx];
            q.push({ny, nx});
        }
    }
}

int main(){
    FastIO;
    while(true){
        cin >> n;
        if(!n) break;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> board[i][j];
                visited[i][j] = INT_MAX;
            }
        }
        bfs();
        cout << "Problem " << cnt  << ": " << visited[n-1][n-1] << "\n";
        cnt++;
    }
    return 0;
}