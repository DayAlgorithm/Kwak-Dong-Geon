#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n, m;
int visited[100001];
vector<pair<int, int>> adj[100001];
long long dist[100001];

long long dijkstra(int start){
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    
    fill(dist, dist + n, LONG_MAX);
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()){
        long long cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if(cost > dist[here]) continue;
        
        for(auto& edge : adj[here]){
            int there = edge.first, w = edge.second;
            
            if(visited[there] == 1 && there != n-1) continue;
            
            if(dist[there] > dist[here] + w){
                dist[there] = dist[here] + w;
                pq.push({dist[there], there});
            }
        }
    }

    return dist[n-1] == LONG_MAX ? -1 : dist[n-1];
}

int main(){
    FastIO;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> visited[i];
    }
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    cout << dijkstra(0);
    
    return 0;
}
