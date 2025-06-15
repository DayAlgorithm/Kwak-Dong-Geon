#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n, m, t = 1, cnt;
vector<vector<int>> adj;

int visited[501];
bool bfs(int start){
    queue<pair<int, int>> q;
    visited[start] = 1;
    q.push({start, -1});
    while(!q.empty()){
        int here = q.front().first, p = q.front().second;
        q.pop();
        for(auto there : adj[here]){
            if(there == p) continue;
            if(!visited[there]){
                visited[there] = 1;
                q.push({there, here});
            }
            else return false;
        }
    }
    return true;
}

int main(){
    FastIO;
    while(true){
        cin >> n >> m;
        if(!n && !m) break;
        adj = vector<vector<int>>(n+1);
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        int u, v;
        for(int i = 0; i < m; ++i){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 1; i <= n; ++i){
            if(!visited[i]){
                if (bfs(i)) cnt++;
            }
        }
        if(!cnt) cout << "Case " << t << ": No trees.\n";
        else if(cnt == 1) cout <<  "Case " << t << ": There is one tree.\n";
        else  cout << "Case " << t << ": A forest of " << cnt << " trees.\n";
        t++;
    }
    return 0;
}