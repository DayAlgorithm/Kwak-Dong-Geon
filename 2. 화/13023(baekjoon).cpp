#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n, m;
vector<vector<int>> adj;

int visited[2001];
bool dfs(int idx, int cnt){
    if(cnt == 4) return true;
    bool ret = false;
    for(int there : adj[idx]){
        if(!visited[there]){
            visited[there] = 1;
            ret = dfs(there, cnt + 1);
            visited[there] = 0;
            if(ret) return ret;
        }
    }
    return ret;
}

int main(){
    FastIO;
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    int u, v;
    for(int i = 0; i < m; ++i){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int i;
    for(i = 0; i < n; ++i){
        memset(visited, 0, sizeof(visited));
        visited[i] = 1;
        if(dfs(i, 0)) break;
    }
    if(i == n) cout << 0;
    else cout << 1;
    return 0;
}