#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int dy[5] = {0, 0, 0, 1, -1};
const int dx[5] = {0, 1, -1, 0, 0};

int m, n, sDir, eDir, cnt;
int board[101][101];
pair<int, int> start, goal;

int visited[101][101][5];

//방향 회전에 필요한 명령 횟수 반환환
int turn(int dir1, int dir2) {
    if (dir1 == dir2) return 0;
    if ((dir1 == 1 && dir2 == 2) || (dir1 == 2 && dir2 == 1) 
        || (dir1 == 3 && dir2 == 4) || (dir1 == 4 && dir2 == 3)) {
        return 2;
    }
    return 1;
}


void bfs(){
    queue<pair<pair<int, int>, int>> q;
    q.push({start, sDir});
    visited[start.first][start.second][sDir] = 1;
    
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int dir = q.front().second;
        q.pop();
        //도착하면 끝
        if(y == goal.first && x == goal.second && dir == eDir) return;

        //방향 회전
        for(int ndir = 1; ndir <= 4; ++ndir){
            if(ndir == dir) continue;
            int cost = visited[y][x][dir] + turn(dir, ndir);
            if(!visited[y][x][ndir] || cost < visited[y][x][ndir]){
                visited[y][x][ndir] = cost;
                q.push({{y, x}, ndir});
            }
        }
        
        //1-3 칸 이동동
        for(int i = 1; i <= 3; ++i){
            int ny = y + i * dy[dir], nx = x + i  * dx[dir];
            if(ny <= 0 || ny > m || nx <= 0 || nx > n || board[ny][nx] == 1) break;
            int cost = visited[y][x][dir] + 1;
            if(!visited[ny][nx][dir] || cost < visited[ny][nx][dir]){
                visited[ny][nx][dir] = cost;
                q.push({{ny, nx}, dir});
            }
        }
    }
}

int main(){
    FastIO;
    cin >> m >> n;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> board[i][j];
        }
    }
    cin >> start.first >> start.second >> sDir;
    cin >> goal.first >> goal.second >> eDir;
    bfs();
    cout << visited[goal.first][goal.second][eDir] - 1;
    return 0;
}