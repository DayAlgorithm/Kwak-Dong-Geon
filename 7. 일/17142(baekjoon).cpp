#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

int n, m;
int board[51][51];
vector<pair<int, int>> virus;
vector<int> chose;
int emptyCnt = 0;

int visited[51][51];
queue<pair<int, int>> q;
int bfs(){
    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] != -1) continue;
            if(board[ny][nx] == 1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    
    int ret = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(board[i][j] == 0){
                if(visited[i][j] == -1) return INT_MAX;
                ret = max(ret, visited[i][j]);
            }
        }
    }
    return ret;
}

int solve(int cnt, int start) {
    if(cnt == m) {
        memset(visited, -1, sizeof(visited));
        while(!q.empty()) q.pop();
        for(auto idx : chose){
            int y = virus[idx].first, x = virus[idx].second;
            visited[y][x] = 0;
            q.push({y, x});
        }
        return bfs();
    }
    
    int ret = INT_MAX;
    for(int i = start; i < virus.size(); ++i){
        chose.push_back(i);
        ret = min(ret, solve(cnt + 1, i + 1));
        chose.pop_back();
    }
    return ret;
}

int main(){
    FastIO;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> board[i][j];
            if(board[i][j] == 2) virus.emplace_back(make_pair(i, j));
            else if(board[i][j] == 0) emptyCnt++;
        }
    }
    
    if(!emptyCnt){
        cout << 0;
        return 0;
    }
    
    int ans = solve(0, 0);
    if(ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}
