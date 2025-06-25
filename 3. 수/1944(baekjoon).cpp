#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

int n, m;
vector<string> board;
vector<pair<int, int>> points;
vector<vector<int>> dist;

int bfs(pair<int,int> start, pair<int,int> end) {
    if(start == end) return 0;
    
    vector<vector<int>> visited(n, vector<int>(n, -1));
    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = 0;

    while(!q.empty()) {
        int y = q.front().first, x = q.front().second; 
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if(visited[ny][nx] != -1) continue;
            if(board[ny][nx] == '1') continue;
            
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            
            if(ny == end.first && nx == end.second) {
                return visited[ny][nx];
            }
        }
    }
    return -1;
}

int prim() {
    int size = points.size();
    if(size <= 1) return 0;
    
    vector<bool> visited(size, false);
    vector<int> minEdge(size, INT_MAX);
    minEdge[0] = 0;
    int ret = 0;

    for(int i = 0; i < size; ++i){
        int u = -1;
        for(int j = 0; j < size; ++j){
            if(!visited[j] && (u == -1 || minEdge[j] < minEdge[u])){
                u = j;
            }
        }

        if(minEdge[u] == INT_MAX) return -1;

        visited[u] = true;
        ret += minEdge[u];

        for(int v = 0; v < size; v++){
            if(!visited[v] && dist[u][v] != -1 && dist[u][v] < minEdge[v]) {
                minEdge[v] = dist[u][v];
            }
        }
    }

    return ret;
}

int main() {
    FastIO;
    cin >> n >> m;
    board.resize(n);
    
    for(int i = 0; i < n; ++i){
        cin >> board[i];
        for(int j = 0; j < n; ++j){
            if(board[i][j] == 'S' || board[i][j] == 'K'){
                points.push_back({i, j});
            }
        }
    }

    int size = points.size();
    dist.assign(size, vector<int>(size, 0));

    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            dist[i][j] = bfs(points[i], points[j]);
        }
    }

    int ans = prim();
    cout << ans << '\n';
    return 0;
}
