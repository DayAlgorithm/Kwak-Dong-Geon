#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int board[102][102], ans;

void bfs(int characterX, int characterY, int itemX, int itemY){
    queue<pair<int,int>> q;
    vector<vector<int>> dist(102, vector<int>(102, -1));
    q.push({characterX * 2, characterY * 2});
    dist[characterX * 2][characterY * 2] = 0;
    while(!q.empty()) {
        auto [x, y] = q.front(); 
        q.pop();
        if(x == itemX * 2 && y == itemY * 2){
            ans = dist[x][y] / 2;
            break;
        }
        for(int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if(nx < 0 || ny < 0 || nx > 100 || ny > 100) continue;
            if(board[nx][ny] != 1 || dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    for (auto& rec : rectangle) {
        int x1 = rec[0] * 2, y1 = rec[1] * 2, x2 = rec[2] * 2, y2 = rec[3] * 2;
        for(int x = x1; x <= x2; ++x) {
            for(int y = y1; y <= y2; ++y) {
                if(x == x1 || x == x2 || y == y1 || y == y2) {
                    if(board[x][y] == 0) board[x][y] = 1;
                } 
                else{
                    board[x][y] = 2;
                }
            }
        }
    }
    bfs(characterX, characterY, itemX, itemY);
    return ans;
}
