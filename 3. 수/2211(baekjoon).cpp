#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;

int dist[1001], path[1001];
void dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()){
        int d = pq.top().first, here = pq.top().second;
        pq.pop();
        for(auto next : adj[here]){
            int there = next.first, cost = next.second;
            if(dist[there] > d + cost){
                dist[there] = d + cost;
                path[there] = here;
                pq.push({d + cost, there});
            }
        }
    }
}

int main(){
    FastIO;
    cin >> n >> m;
    adj = vector<vector<pair<int, int>>>(n + 1);
    int a, b, c;
    for(int i = 0; i < n; ++i){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    fill(dist, dist + 1001, INT_MAX);
    dijkstra();
    cout << n - 1 << "\n";
    for(int i = 2; i <= n; ++i){
        cout << i << " " << path[i] << "\n";
    }
    return 0;
}