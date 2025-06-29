#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

int ans;
bool visited[25];
vector<string> board;

bool checkS(){
    int cnt = 0;
    for(int i = 0; i < 25; ++i){
        if(visited[i]){
            int y = i / 5, x = i % 5;
            if(board[y][x] == 'S') cnt++;
        }
    }
    if(cnt >= 4) return true;
    return false;
}

bool check(int idx){
    queue<pair<int,int>> q;
    bool vis[5][5] = {};
    int cnt = 1;
    q.push({idx / 5, idx % 5});
    vis[idx / 5][idx % 5] = true;
    while(!q.empty()){
        int y = q.front().first, x = q.front().second; 
        q.pop();
        for(int i = 0; i < 4; ++i) {
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5 || vis[ny][nx]) continue;
            int there = ny * 5 + nx;
            if(visited[there]){
                vis[ny][nx] = true;
                q.push({ny, nx});
                cnt++;
            }
        }
    }
    return cnt == 7;
}

void dfs(int idx, int cnt){
    if(cnt == 7){
        if(checkS() && check(idx)) ans++;
        return;
    }
    
    for(int i = idx; i < 25; ++i){
        if(!visited[i]){
            visited[i] = true;
            dfs(i, cnt + 1);
            visited[i] = false;
        }
    }
}

int main(){
    FastIO;
    board.resize(5);
    for(int i = 0; i < 5; ++i) cin >> board[i];
    dfs(0, 0);
    cout << ans;
    return 0;
}