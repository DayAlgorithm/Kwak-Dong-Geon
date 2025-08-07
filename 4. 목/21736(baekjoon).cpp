#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

int n, m;
int startY, startX;
string school[600];

bool visited[600][600];
int ans = 0;

void dfs(int y, int x){
    if(school[y][x] == 'P') ans++;

    visited[y][x] = true;
    for(int i = 0; i < 4; ++i){
        int ny = y + dy[i], nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(!visited[ny][nx]){
            if(school[ny][nx] == 'X') visited[ny][nx] = true;
            else dfs(ny, nx);
        }
    }
}

int main(){
    FastIO;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char c;
            cin >> c;
            school[i].push_back(c);
            if(c == 'I'){
                startY = i;
                startX = j;
            }
        }
    }
    dfs(startY, startX);
    if(!ans) cout << "TT"; 
    else cout << ans;
    return 0;
}