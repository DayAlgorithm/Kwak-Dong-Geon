#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n, ans;
vector<vector<int>> adj;

//각 노드가 얼리어답터인지 아닌지에 따라 자식 중에 얼리어답터의 수의 최솟값 저장
int visited[1000001][2];
void cnt(int node){
    //얼리어답터인 경우 1추가
    visited[node][0] = 1;
    for(auto& i : adj[node]){
        //이미 방문한 정점은 패스
        if(visited[i][0] || visited[i][1]) continue;
        cnt(i);
        visited[node][1] += visited[i][0];  //현재 얼리어답터가 아닌 경우 자식은 모두 얼리어답터 
        visited[node][0] += min(visited[i][0], visited[i][1]);  //얼리어답터인 경우는 둘중 작은거 고르기
    }
}

int main(){
    FastIO;
    cin >> n;
    int u, v;
    adj = vector<vector<int>>(n + 1);
    for(int i = 1; i < n; ++i){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cnt(1);
    ans = min(visited[1][0], visited[1][1]);
    cout << ans;
    return 0;
}