#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m;
int adj[1001][1001];

void floyd(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(adj[i][k] && adj[k][j]){
                    if(adj[i][j] == 0) adj[i][j] = adj[i][k] + adj[k][j];
                    else adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }
}

int main() {
    FastIO;
    cin >> n >> m;
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    floyd();
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        cout << adj[u][v] << '\n';
    }
    return 0;
}
