#include<bits/stdc++.h>
using namespace std;

//칸 이동 방향향
const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};

int visited[101][101];  //방문 처리(발견 순서)
queue<pair<int, int>> q; 
int bfs(const vector<vector<int>>& maps, int startY, int startX){
    int n = maps.size(), m = maps[0].size();
    q.push({startY, startX});
    visited[startY][startX] = 1;
    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny == n - 1 && nx == m - 1) return visited[y][x] + 1;    //상대 진영에 도달한 경우 바로 return
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]
               || !maps[ny][nx]) continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }
    return -1;  //상대 진영에 도달하지 못한경우
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    answer = bfs(maps, 0, 0);
    return answer;
}