#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int dy[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
const int dx[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

vector<int> newline(8, 0);
deque<vector<int>> maze;

bool bfs(){
    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()){
        int size = q.size();
        bool visited[8][8] = {false,};
        for(int s = 0; s < size; ++s){
            int y = q.front().first, x = q.front().second;
            q.pop();

            if(maze[y][x]) continue;
            if(y == 7 && x == 7) return true;

            for(int i = 0; i < 9; ++i){
                int ny = y + dy[i], nx = x + dx[i];
                if(ny < 0 || ny >= 8 || nx < 0 || nx >= 8) continue;
                if(maze[ny][nx]) continue;
                if(!visited[ny][nx]){
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
        maze.pop_front();
        maze.push_back(newline);
    }
    return false;
}
int main(){
    FastIO;
    string str;
    for(int i = 0; i < 8; ++i){
        cin >> str;
        vector<int> line;
        for(int j = 0; j < 8; ++j){
            if(str[j] == '#') line.push_back(1);
            else line.push_back(0); 
        }
        maze.push_back(line);
    }
    reverse(maze.begin(), maze.end());
    if(bfs()) cout << 1;
    else cout << 0;
    return 0;
}
