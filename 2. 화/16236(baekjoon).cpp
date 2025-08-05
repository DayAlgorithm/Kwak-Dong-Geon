#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int dy[] = {-1, 0, 0, 1};
const int dx[] = {0, -1, 1, 0};

int n, cnt, ans;
int board[21][21];
pair<pair<int, int>, int> shark;

bool eat(){
    vector<vector<int>> visited(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    vector<pair<int, int>> fish;
    int minDis = INT_MAX;
    q.push(shark.first);
    visited[shark.first.first][shark.first.second] = 0;
    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        if(visited[y][x] > minDis) continue;
        for(int i = 0; i < 4; ++i){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < n && visited[ny][nx] == -1 && board[ny][nx] <= shark.second){
                visited[ny][nx] = visited[y][x] + 1;
                if(board[ny][nx] && board[ny][nx] < shark.second){
                    if(visited[ny][nx] < minDis){
                        minDis = visited[ny][nx];
                        fish.clear();
                    }
                    if(visited[ny][nx] == minDis) fish.push_back({ny, nx});
                }
                q.push({ny, nx});
            }
        }
    }
    if(fish.empty()) return false;
    sort(fish.begin(), fish.end());
    cnt++;
    board[fish.front().first][fish.front().second] = 0;
    ans += visited[fish.front().first][fish.front().second];
    shark.first = fish.front();
    return true;
}

void solve(){
    while(true){
        if(eat()){
            if(cnt == shark.second){
                cnt = 0;
                shark.second++;
            }
        } 
        else return;
    }
}

int main(){
    FastIO;
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> board[i][j];
            if(board[i][j] == 9){
                shark.first = {i, j};
                shark.second = 2;
                board[i][j] = 0;
            }  
        }
    }
    solve();
    cout << ans;
    return 0;
}