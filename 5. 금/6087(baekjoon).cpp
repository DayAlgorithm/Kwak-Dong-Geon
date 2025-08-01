#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int w, h;
int board[101][101];
vector<pair<int, int>> c;
int dist[101][101][4];

int dijkstra() {
    memset(dist, -1, sizeof(dist));
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
    int sy = c[0].first, sx = c[0].second;
    int ey = c[1].first, ex = c[1].second;

    for(int i = 0; i < 4; ++i) {
        dist[sy][sx][i] = 0;
        pq.push({0, sy, sx, i});
    }

    while(!pq.empty()){
        int cost = get<0>(pq.top());
        int y = get<1>(pq.top()), x = get<2>(pq.top()), d = get<3>(pq.top());
        pq.pop();

        if(dist[y][x][d] < cost) continue;
        if(y == ey && x == ex) continue;

        for(int i = 0; i<4; ++i){
            int ncost = cost;
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || ny >= h || nx < 0 || nx >= w || board[ny][nx] == 1) continue;
            if(i != d) ncost++;
            if(dist[ny][nx][i] == -1 || dist[ny][nx][i] > ncost) {
                dist[ny][nx][i] = ncost;
                pq.push({ncost, ny, nx, i});
            }
        }
    }

    int ret = INT_MAX;
    for(int d = 0; d < 4; ++d){
        if(dist[ey][ex][d] != -1) ret = min(ret, dist[ey][ex][d]);
    }
    return ret;
}

int main() {
    FastIO;
    cin >> w >> h;
    for (int i = 0; i < h; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < w; ++j) {
            if (line[j] == 'C') c.push_back({i, j});
            if (line[j] == '*') board[i][j] = 1;
        }
    }
    cout << dijkstra() << "\n";
    return 0;
}
