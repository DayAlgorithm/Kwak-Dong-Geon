#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n, m, s, e;
vector<vector<int>> adj;

int visited[300001];
int bfs(){
    queue<pair<int, int>> q;
    q.push({s, 0});
    visited[s] = 1;
    while(!q.empty()){
        int here = q.front().first, cnt = q.front().second;
        q.pop();
        if(here == e) return cnt;   //e에 도착하면 걸린 시간 리턴턴
        if(here - 1 > 0 && !visited[here - 1]){ //x-1로 이동
            visited[here - 1] = 1;
            q.push({here - 1, cnt + 1});
        }
        if(here + 1 <= n && !visited[here + 1]){ //x+1로 이동동
            visited[here + 1] = 1;
            q.push({here + 1, cnt + 1});
        }
        for(auto there : adj[here]){    //연결 되어있는 포탈로 이동동
            if(!visited[there]){
                visited[there] = 1;
                q.push({there, cnt + 1});
            }
        }
    }
    return -1;  //e에 갈 수 없는 경우우
}

int main(){
    FastIO;
    cin >> n >> m >> s >> e;
    adj = vector<vector<int>>(n + 1);
    int x, y;
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        //양방향 그래프프
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << bfs();
    return 0;
}