#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n, work[10001], degree[10001], ans;
vector<vector<int>> adj;    

int visited[10001];
queue<int> q;
void bfs(){
    for(int i = 1; i <= n; ++i){
        if(!degree[i]){ //선행 작업이 필요없는 것부터 진행행
            q.push(i);
            visited[i] = work[i];
            ans = max(ans, work[i]);
        }
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0; i < adj[now].size(); ++i){
            int next = adj[now][i];
            //가장 늦게 끝나는 선행작업 기준으로 작업 시작작
            visited[next] = max(visited[next], visited[now] + work[next]);
            ans = max(ans, visited[next]);
            --degree[next];
            if(!degree[next]) q.push(next);
        }
    }
}

int main(){
    FastIO;
    cin >> n;
    adj = vector<vector<int>>(n + 1);
    int c, v;
    for(int i = 1; i <= n; ++i){
        cin >> work[i] >> c;
        for(int j = 0; j < c; ++j){
            cin >> v;
            adj[v].push_back(i);
            degree[i]++;    //들어오는 차수 저장장
        }
    }
    bfs();
    cout << ans << "\n";
    return 0;
}