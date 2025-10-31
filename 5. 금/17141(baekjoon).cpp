#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int n, m, ans = INT_MAX;
int board[51][51];
bool visited[51][51];
vector<pair<int, int>> virus_pos;
vector<int> selected;

bool checkAll(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(board[i][j] != 1 && !visited[i][j])
                return false;
        }
    }
    return true;
}

void bfs(){
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    
    for(int idx : selected){
        int x = virus_pos[idx].first;
        int y = virus_pos[idx].second;
        q.push({x, y});
        visited[x][y] = true;
    }
    
    int time = 0;
    while(!q.empty()){
        int qsize = q.size();
        for(int i = 0; i < qsize; ++i){
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int d = 0; d < 4; ++d){
                int nx = x + dx[d], ny = y + dy[d];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(visited[nx][ny] || board[nx][ny] == 1) continue;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        if(!q.empty()) time++;
    }
    
    if(checkAll()) ans = min(ans, time);
}

void combination(int idx, int cnt){
    if(cnt == m){
        bfs();
        return;
    }
    for(int i = idx; i < virus_pos.size(); ++i){
        selected.push_back(i);
        combination(i + 1, cnt + 1);
        selected.pop_back();
    }
}

int main(){
    FastIO;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> board[i][j];
            if(board[i][j] == 2)
                virus_pos.push_back({i, j});
        }
    }
    
    combination(0, 0);
    if(ans == INT_MAX) ans = -1;
    cout << ans;
    
    return 0;
}
