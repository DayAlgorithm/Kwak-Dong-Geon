#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m, k;
vector<vector<tuple<int, int, bool>>> adj; // {to, cost, isActive}

int prim() {
    vector<bool> visited(n + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int cnt = 0, mst = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int cost = pq.top().first, here = pq.top().second;
        pq.pop();
        if (visited[here]) continue;
        visited[here] = true;
        mst += cost;
        cnt++;
        for(auto& edge : adj[here]) {
            int to = get<0>(edge);
            int w = get<1>(edge);
            bool flag = get<2>(edge);
            if (!visited[to] && flag) {
                pq.push({w, to});
            }
        }
    }
    if(cnt == n) return mst;
    else return 0;
}

void remove() {
    int minCost = INT_MAX, from = -1, to = -1;
    for(int u = 1; u <= n; ++u){
        for(auto& edge : adj[u]){
            int v = get<0>(edge);
            int w = get<1>(edge);
            bool flag = get<2>(edge);
            if(u < v && flag && w < minCost) {
                minCost = w;
                from = u;
                to = v;
            }
        }
    }

    for(auto& edge : adj[from]){
        if(get<0>(edge) == to && get<1>(edge) == minCost && get<2>(edge)) {
            get<2>(edge) = false;
            break;
        }
    }
    for(auto& edge : adj[to]){
        if(get<0>(edge) == from && get<1>(edge) == minCost && get<2>(edge)) {
            get<2>(edge) = false;
            break;
        }
    }
}

int main() {
    FastIO;
    cin >> n >> m >> k;
    adj = vector<vector<tuple<int, int, bool>>>(n + 1);
    int u, v;
    for(int i = 1; i <= m; ++i) {
        cin >> u >> v;
        adj[u].push_back({v, i, true});
        adj[v].push_back({u, i, true});
    }
    for(int i = 0; i < k; ++i) {
        int mst = prim();
        if(!mst){
            for(int t = i; t < k; ++t) cout << "0 ";
            break;
        }
        cout << mst << ' ';
        remove();
    }
    return 0;
}
