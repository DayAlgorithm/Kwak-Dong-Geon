#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, start, goal;
vector<string> state;
vector<int> dist;

int calcCost(int u, int v) {
    string s1 = state[u], s2 = state[v];
    int ret = 0;
    for (size_t i = 0; i < s1.length(); ++i) {
        int cost = s1[i] - s2[i];
        ret += cost * cost;
    }
    return ret;
}

void dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int cost = pq.top().first, here = pq.top().second;
        pq.pop();

        if(dist[here] < cost) continue;
        for(int there = 1; there <= n; ++there){
            if(here == there) continue;

            int ncost = cost + calcCost(here, there);
            if(dist[there] > ncost){
                dist[there] = ncost;
                pq.push({ncost, there});
            }
        }
    }
}

int main() {
    FastIO;
    cin >> n;
    state.resize(n + 1);
    dist.resize(n + 1, INT_MAX);
    for (int i = 1; i <= n; ++i) {
        cin >> state[i];
    }

    cin >> start >> goal;

    dijkstra();
    cout << dist[goal] << '\n';

    return 0;
}
