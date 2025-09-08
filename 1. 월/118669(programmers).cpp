#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> ans = {0, INT_MAX};
set<int> peak;

vector<int> visited;
void dijkstra(vector<int>& gates){
    priority_queue<pair<int, int>> pq;
    for(auto& start : gates){
        pq.push({0, start});
        visited[start] = 0;
    }
    while(!pq.empty()){
        pair<int, int> here = pq.top();
        pq.pop();
        if(ans[0] && ans[1] < -here.first) continue;
        if(peak.find(here.second) != peak.end()){
            if(ans[1] > -here.first){
                ans[1] = -here.first;
                ans[0] = here.second;
            } 
            else if(ans[1] == -here.first && ans[0] > here.second) ans[0] = here.second;
            continue;
        }
        for(auto& there : adj[here.second]){
            int cost = max(-here.first, there.first);
            if(visited[there.second] > cost){
                visited[there.second] = cost;
                pq.emplace(-visited[there.second], there.second);
            }
        }
    }       
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    adj = vector<vector<pair<int, int>>>(n + 1);
    for(int i = 0; i < paths.size(); ++i){
        adj[paths[i][0]].push_back({paths[i][2], paths[i][1]});
        adj[paths[i][1]].push_back({paths[i][2], paths[i][0]});
    }
    peak = set<int>(summits.begin(), summits.end());
    visited = vector<int>(n + 1, INT_MAX);
    dijkstra(gates);
    return ans;
}