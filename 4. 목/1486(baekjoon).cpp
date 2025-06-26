#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

int n, m, t, d, ans;
int height[26][26], distUp[26][26], distDown[26][26];

int getHeight(char c) {
    if(c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

int getCost(int h1, int h2) {
    if(h1 >= h2) return 1;
    return (h2 - h1) * (h2 - h1);
}

void dijkstra(int dist[26][26], int starty, int startx, bool flag) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            dist[i][j] = INT_MAX;
        }
    }
    
    dist[starty][startx] = 0;
    pq.push({0, {starty, startx}});
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int y = pq.top().second.first, x = pq.top().second.second;
        pq.pop();
        
        if(dist[y][x] < cost) continue;
        for(int i = 0; i < 4; ++i){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(abs(height[ny][nx] - height[y][x]) > t) continue;
            int ncost;
            if(flag) ncost = cost + getCost(height[y][x], height[ny][nx]);
            else ncost = cost + getCost(height[ny][nx], height[y][x]);
            if(dist[ny][nx] > ncost){
                dist[ny][nx] = ncost;
                pq.push({ncost, {ny, nx}});
            }
        }
    }
}

int main() {
    FastIO;
    cin >> n >> m >> t >> d;
    
    string str;
    for(int i = 0; i < n; ++i){
        cin >> str;
        for(int j = 0; j < m; ++j){
            height[i][j] = getHeight(str[j]);
        }
    }
    
    dijkstra(distUp, 0, 0, true);
    dijkstra(distDown, 0, 0, false);
    
    ans = height[0][0];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(distUp[i][j] == INT_MAX || distDown[i][j] == INT_MAX) continue;
            if(distUp[i][j] + distDown[i][j] <= d){
                ans = max(ans, height[i][j]);
            }
        }
    }
    cout << ans;
    return 0;
}
