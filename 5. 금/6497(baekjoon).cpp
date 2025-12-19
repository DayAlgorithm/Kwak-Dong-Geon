#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int m, n, total, sum;

int prim(){
    vector<vector<pair<int, int>>> adj(m);
    
    for(int i = 0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
        total += z;
    }
    
    vector<bool> visited(m, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, 0});
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(visited[node]) continue;
        
        visited[node] = true;
        sum += cost;
        
        for(auto& edge : adj[node]){
            int next = edge.first;
            int weight = edge.second;
            if(!visited[next]){
                pq.push({weight, next});
            }
        }
    }
    
    return total - sum;
}

int main() {
    FastIO;
    while(true){
        cin >> m >> n;
        if(m == 0 && n == 0) break;
        total = 0;
        sum = 0;
        cout << prim() << '\n';
    }
    
    return 0;
}
