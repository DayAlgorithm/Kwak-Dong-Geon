#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, k;
int board[10][10];
int dist[1 << 10][10];

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

void floyd() {
    for (int l = 0; l < n; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] = min(board[i][j], board[i][l] + board[l][j]);
            }
        }
    }
}

int dijkstra() {
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = INT_MAX;
        }
    }

    pq.push({0, k, (1 << (k))});
    dist[1 << (k)][k] = 0;

    while(!pq.empty()){
        int cost = get<0>(pq.top()), here = get<1>(pq.top()), visited = get<2>(pq.top());
        pq.pop();

        if(dist[visited][here] < cost) continue;

        for(int there = 0; there < n; ++there){
            int ncost = cost + board[here][there], nvisited = visited | (1 << there);
            
            if(ncost < dist[nvisited][there]){
                dist[nvisited][there] = ncost;
                pq.push({ncost, there, nvisited});
            }
        }
    }

    int ret = INT_MAX;
    int allvisited = (1 << n) - 1;
    for (int i = 0; i < n; ++i) {
        ret = min(ret, dist[allvisited][i]);
    }
    
    return ret;
}

int main() {
    FastIO;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }
    
    floyd();
    cout << dijkstra();
    return 0;
}