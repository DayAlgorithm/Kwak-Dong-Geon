#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int T;

vector<int> dijkstra(int n, int s, vector<vector<pair<int, int>>>& adj){
    vector<int> dist(n + 1, 987654321);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()){
        int cost = pq.top().first, here = pq.top().second;
        pq.pop();

        if(cost > dist[here]) continue;
        for(auto& edge : adj[here]){
            int there = edge.second, weight = edge.first;
            if(dist[there] > cost + weight){
                dist[there] = cost + weight;
                pq.push({cost + weight, there});
            }
        }
    }
    return dist;
}

vector<int> findDest(int n, int s, int g, int h, int gh_weight, vector<vector<pair<int, int>>>& adj, vector<int>& goals){
    vector<int> ret;

    vector<int> dist_s = dijkstra(n, s, adj), dist_g = dijkstra(n, g, adj), dist_h = dijkstra(n, h, adj);
    for(int dest : goals){
            int dist = dist_s[dest];
            int path1 = dist_s[g] + gh_weight + dist_h[dest];
            int path2 = dist_s[h] + gh_weight + dist_g[dest];
        if(dist == min(path1, path2)) ret.push_back(dest);
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main(){
    FastIO;
    cin >> T;
    int n, m, t, s, g, h; 
    while(T--){
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        int gh_weight = 0;
        vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>(n + 1));
        for(int i =0; i < m; ++i){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
            if((u == g && v == h) || (u == h && v == g)){
                gh_weight = w;
            }
        }

        vector<int> goals(t);
        for(int i = 0; i < t; ++i){
            cin >> goals[i];
        }

        vector<int> ans = findDest(n, s, g, h, gh_weight, adj, goals);
        for(auto i : ans){
            cout << i << " ";
        }
        cout << "\n";
    }    
    return 0;
}