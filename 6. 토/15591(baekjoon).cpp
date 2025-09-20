#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, Q;
vector<pair<int, int>> adj[5001];

int bfs(int k, int v){
    queue<pair<int, int>> q;
    q.push({v, INT_MAX});
    vector<bool> visited(n + 1, false);
    visited[v] = true;

    int cnt = 0;
    while(!q.empty()){
        int here = q.front().first, cost = q.front().second;
        q.pop();

        for(auto& a : adj[here]){
            int there = a.first, r = a.second;
            if(!visited[there]){
                int ncost = min(cost, r);
                if(ncost >= k){
                    visited[there] = true;
                    q.push({there, ncost});
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int main(){
    FastIO;
    cin >> n >> Q;

    for(int i = 0; i < n - 1; ++i){
        int u, v, r;
        cin >> u >> v >> r;
        adj[u].push_back({v, r});
        adj[v].push_back({u, r});
    }

    for(int i = 0; i < Q; ++i){
        int k, v;
        cin >> k >> v;

        cout << bfs(k, v) << "\n";
    }
    return 0;
}