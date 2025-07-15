#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int w, h, ans;
vector<vector<int>> room;
vector<pair<int, int>> point;
vector<bool> clean;

int dist[11][11];
int bfs(pair<int, int> start, pair<int, int> end) {
    vector<vector<int>> visited(h, vector<int>(w, -1));
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = 0;
    
    while(!q.empty()) {
        int y = q.front().first, x = q.front().second;
        q.pop();
        if(y == end.first && x == end.second) return visited[y][x];
        
        for(int i = 0; i < 4; ++i) {
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if(room[ny][nx] == -1 || visited[ny][nx] != -1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    return -1;
}

void minPath(int now, int idx, int sum, int size) {
    if(idx == size) {
        ans = min(ans, sum);
        return;
    }

    for(int i = 1; i < size; ++i) {
        if(!clean[i] && dist[now][i] != -1) {
            clean[i] = true;
            minPath(i, idx + 1, sum + dist[now][i], size);
            clean[i] = false;
        }
    }
}

int main(){
    FastIO;
    while(true){
        cin >> w >> h;
        if(!w && !h) break; 
        room = vector<vector<int>>(h, vector<int>(w, 0));
        point.clear();

        for(int i = 0; i < h; ++i){
            string str;
            cin >> str;
            for(int j = 0; j < w; ++j){
                if(str[j] == '*'){
                    room[i][j] = 1;
                    point.push_back({i, j});
                }
                else if(str[j] == 'x') {
                    room[i][j] = -1;
                }
                else if(str[j] == 'o'){
                    point.insert(point.begin(), {i, j});
                }
            }
        }

        int size = point.size();
        bool flag = false;
        for(int i = 0; i < size; ++i){
            for(int j = 0; j < size; ++j){
                if(i == j) dist[i][j] = 0;
                else{
                    dist[i][j] = bfs(point[i], point[j]);
                    if(dist[i][j] == -1) flag = true;
                }
            }
        }

        if(flag){
            cout << -1 << '\n';
            continue;
        }

        clean = vector<bool>(size, false);
        clean[0] = true;
        ans = INT_MAX;
        minPath(0, 1, 0, size);
        cout << ans << '\n';
    }
    return 0;
}
