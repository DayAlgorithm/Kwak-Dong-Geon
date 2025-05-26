#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n, k;
vector<int> adj[18];
int node[18];
int maxScore = -1, maxApple, maxPear;

int popcount(int mask) {
    return __builtin_popcount(mask);
}

void bfs(){
    //방문 여부를 비트마스킹으로 저장장
    set<int> visited;
    queue<pair<int, int>> q;
    
    int initMask = 1 << 0;
    q.push({initMask, 1});
    visited.insert(initMask);
    
    while(!q.empty()){
        int mask = q.front().first, cnt = q.front().second;
        q.pop();
        int apple = 0, pear = 0;
        for(int i = 0; i < n; ++i){
            if(mask & (1 << i)){
                if(node[i] == 1) apple++;
                else if(node[i] == 2) pear++;
            }
        }
        
        int score = apple * pear;
        if(maxScore < score || 
           (maxScore == score && maxApple < apple) ||
           //이거 왜 있어야 하는지 모르겠음. 없으니까 틀림...
           (maxScore == score && maxApple == apple && maxPear < pear)){
            maxScore = score;
            maxApple = apple;
            maxPear = pear;
        }
        
        for(int i = 0; i < n; ++i){
            if(mask & (1 << i)){
                for(auto next : adj[i]){
                    if(!(mask & (1 << next))){
                        int newMask = mask | (1 << next);
                        if(popcount(newMask) <= k && visited.find(newMask) == visited.end()){
                            visited.insert(newMask);
                            q.push({newMask, cnt + 1});
                        }
                    }
                }
            }
        }
    }
}

int main(){
    FastIO;
    cin >> n >> k;
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; ++i){
        cin >> node[i];
    }
    
    bfs();
    
    cout << maxApple << " " << maxPear;
    return 0;
}