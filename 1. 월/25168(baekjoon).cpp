#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m;
int degree[10001], visited[10001];
vector<vector<pair<int, int>>> adj;
queue<int> q;

int cnt(){
    int ret = 0;
    while(!q.empty()){
        int here = q.front();
        q.pop();
        ret = max(ret, visited[here]);  //지금까지 가장 오래 걸리는 접종일을 저장
        for(int there = 1; there <= n; ++there){
            for(auto& e : adj[there]){  
                int pre = e.first, w = e.second;
                if(pre == here){    //here을 맞으면 맞을 수 있는 다음 백신 발견
                    int nDay = visited[here] + w;
                    if(nDay >= visited[here] + 7) nDay++;   //유효기간 지나면 +1
                    visited[there] = max(visited[there], nDay);
                    degree[there]--;
                    if(degree[there] == 0) q.push(there);
                    break;
                }
            }
        }
    }
    return ret;
}

int main(){
    FastIO;
    cin >> n >> m;
    adj = vector<vector<pair<int, int>>>(n + 1);
    
    int s, e, w;
    for(int i = 0; i < m; ++i){
        cin >> s >> e >> w;
        adj[e].push_back({s, w});
        degree[e]++;
    }

    for(int i = 1; i <= n; ++i){    //선행 접종이 없는 백신 부터 큐에 넣는다.
        if(!degree[i]){
            q.push(i);
            visited[i] = 1;
        }
    }
    cout << cnt();
    return 0;
}
