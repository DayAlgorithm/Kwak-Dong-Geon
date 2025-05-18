#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = 987654321;

int t, n, m;
vector<vector<pair<int, int>>> adj;
vector<int> path[21];

int visited[21];
void dijkstra(){
    fill(visited, visited + 21, INF);
    for(auto& p : path) p.clear();
    priority_queue<pair<int, int>> pq;
    pq.push({0, 0});
    visited[0] = 0;
    while(!pq.empty()){
        int here = pq.top().second, cost = -pq.top().first;
        pq.pop();
        if(visited[here] < cost) continue;
        for(int i = 0; i < adj[here].size(); ++i){
            int there = adj[here][i].first, ncost = cost + adj[here][i].second;
            if(visited[there] > ncost){
                visited[there] = ncost;
                path[there].clear();
                path[there].push_back(here);
                pq.push({-ncost, there});
            }
            else if(visited[there] == ncost){
                path[there].push_back(here);
            }
        }
    }
}

int main(){
    FastIO;
    cin >> t;
    for(int c = 1; c <= t; ++c){
        cin >> n >> m;
        adj = vector<vector<pair<int, int>>>(m);
        int x, y, w;
        for(int i = 0; i < n; ++i){
            cin >> x >> y >> w;
            //양방향으로 그래프 구성
            adj[x].push_back({y, w});
            adj[y].push_back({x, w});
        }
        dijkstra();
        cout << "Case #" << c << ": ";
        if(visited[m - 1] == INF){  //최고의원에게 도달하지 못한 경우
            cout << -1 << "\n";
            continue;
        }
        //path 역추적
        stack<int> ans;
        int now = m - 1;
        ans.push(now);
        while(now){
            if(path[now].empty()) break;
            now = path[now][0];
            ans.push(now);
        }
        while(!ans.empty()){
            cout << ans.top() << " ";
            ans.pop();
        }
        cout << "\n";
    }    
    return 0;
}