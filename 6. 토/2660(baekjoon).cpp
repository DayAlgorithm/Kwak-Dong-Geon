#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n;
vector<vector<int>> adj;
int score[51];
vector<int> ans;

void bfs(int start){
    queue<int> q;
    q.push(start);
    int visited[51];
    memset(visited, -1, sizeof(visited));
    visited[start] = 0;

    int maxDist = 0;
    while(!q.empty()){
        int here = q.front();
        q.pop();
        for(auto there : adj[here]){
            if(visited[there] == -1){
                visited[there] = visited[here] + 1;
                maxDist = max(maxDist, visited[there]);
                q.push(there);
            }
        }
    }
    score[start] = maxDist;
}

int main(){
    FastIO;
    cin >> n;
    adj = vector<vector<int>>(n + 1);
    int u, v;
    while(true){
        cin >> u >> v;
        if(u == -1) break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int minScore = 51; 
    for(int i = 1; i <= n; ++i){
        bfs(i);
        if(score[i] <= minScore){
            if(score[i] != minScore){
                minScore = score[i];
                ans.clear();
            }
            ans.push_back(i);
        }
    }
    cout << minScore << " " << ans.size() << "\n";
    for(auto a : ans) cout << a << " ";
    return 0;
}