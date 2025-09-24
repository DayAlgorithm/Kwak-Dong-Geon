#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m;
vector<pair<int, int>> adj[1001];

int dist[1001], dp[1001];
void dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 2});
    dist[2] = 0;
    dp[2] = 1;
    while(!pq.empty()){
        int here = pq.top().second, cost = pq.top().first;
        pq.pop();
        if(dist[here] < cost) continue;
        for(auto a : adj[here]){
            int there = a.first, ncost = cost + a.second;
            if(dist[there] > ncost){
                dist[there] = ncost;
                pq.push({ncost, there});
            }
            if(dist[there] < cost) dp[here] += dp[there];
        }
    }
}

int main(){
    FastIO;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    fill(dist, dist + 1001, INT_MAX);
    dijkstra();
    cout << dp[1];
    return 0;
}