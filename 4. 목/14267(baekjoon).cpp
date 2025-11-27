#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m;
vector<int> adj[100001]; 
int val[100001];

void dfs(int now) {
    for (int next : adj[now]) {
        val[next] += val[now];
        dfs(next);
    }
}

int main() {
    FastIO;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int boss;
        cin >> boss;
        if(boss == -1) continue;
        adj[boss].push_back(i);
    }

    for(int i = 0; i < m; i++){
        int u, w;
        cin >> u >> w;
        val[u] += w;
    }

    dfs(1);

    for(int i = 1; i <= n; i++){
        cout << val[i] << " ";
    }
    return 0;
}