#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = 987654321;

int n, m, s, e, cnt = 1;
stack<int> ans;
vector<vector<pair<int, int>>> adj;

int dist[1001];
vector<vector<int>> path; 
priority_queue<pair<int, int>> pq;
//다익스트라 함수
void dijkstra(){
    for(int i = 0; i < 1001; ++i){
        dist[i] = INF;  //최초 값 최대로 설정
    }
    path = vector<vector<int>>(n + 1);
    path[s].push_back(s);
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        pair<int, int> here = pq.top();
        pq.pop();
        if(-here.first > dist[here.second]) continue;
        for(pair<int, int>& there: adj[here.second]){
            int cost = -here.first + there.first;
            if(dist[there.second] > cost){
                dist[there.second] = cost;
                path[there.second].clear(); //최소 경로 업데이트
                path[there.second].push_back(here.second);
                pq.emplace(-dist[there.second], there.second);
            }
            else if(dist[there.second] == cost) path[there.second].push_back(here.second);
        }
    }
}

//경로 역추적
void findPath(){
    ans.push(e);
    int now = e;
    while(true){
        int next = path[now][0];
        ans.push(path[now][0]);
        if(next == s) break;
        now = next;
    }   
}

int main(){
    FastIO;
    cin >> n >> m;
    adj = vector<vector<pair<int, int>>>(n + 1);
    int u, v, w;
    for(int i = 0; i < m; ++i){
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    cin >> s >> e;
    dijkstra();
    findPath();
    cout << dist[e] << "\n" <<  ans.size() << "\n";
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}