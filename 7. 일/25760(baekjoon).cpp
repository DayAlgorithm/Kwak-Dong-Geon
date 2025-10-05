#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> car;
vector<int> visited;

void bfs(){
    queue<int> q;
    q.push(1);
    visited[1] = 1;  // 1번 노드는 거리 1로 시작
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for(int next : adj[now]){
            if(visited[next]) continue;
            visited[next] = visited[now] + 1;
            q.push(next);
        }
    }
}

int main(){
    FastIO;
    cin >> n;
    adj = vector<vector<int>>(n + 1);
    car = vector<bool>(n + 1, false);
    visited = vector<int>(n + 1, 0);
    
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i = 1; i <= n; ++i){
        int c;
        cin >> c;
        if(c) car[i] = true;
    }
    
    bfs();
    
    // 차량이 있는 노드의 거리만 수집
    vector<int> arr;
    for(int i = 1; i <= n; ++i){
        if(car[i]) arr.push_back(visited[i]);
    }
    
    // 내림차순 정렬
    sort(arr.rbegin(), arr.rend());
    
    // 각 차량의 (대기시간 + 이동시간) 최댓값
    int maxTime = 0;
    int time = 0;
    for(auto distance : arr){
        maxTime = max(maxTime, distance + time);
        time++;
    }
    
    cout << maxTime << '\n';
    
    return 0;
}
