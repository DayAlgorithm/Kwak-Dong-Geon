#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n;
long long ans;
vector<vector<int>> adj;

//프림 알고리즘
void prim(){
    bool visited[1001] = {false, };
    //간선 정렬
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    //간선의 개수가 n -1개가 될때 까지
    while(n){
        int cost = pq.top().first, here = pq.top().second;
        pq.pop();
        //방문하지 않은 점만(사이클 방지)
        if(!visited[here]){
            visited[here] = true;
            ans += cost;
            n--;
            //이 정점에서 사용하지 않은 간선은 다시 정렬
            for(int i = 0; i < adj[here].size(); ++i){
                if(!visited[i]) pq.push({adj[here][i], i});
            }
        }
    }
}

int main(){
    FastIO;
    cin >> n; 
    adj = vector<vector<int>>(n, vector<int>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> adj[i][j];
        }
    }
    prim();
    cout << ans;
    return 0;
}