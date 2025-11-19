#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n;
int population[11];
vector<int> adj[11];

bool bfs(vector<int>& group) {
    if(group.empty()) return false;
    
    queue<int> q;
    vector<bool> visited(n, false);
    
    q.push(group[0]);
    visited[group[0]] = true;
    int cnt = 1;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int next : adj[cur]) {
            if(!visited[next] && find(group.begin(), group.end(), next) != group.end()) {
                visited[next] = true;
                q.push(next);
                cnt++;
            }
        }
    }
    
    return cnt == group.size();
}

int main(){
    FastIO;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> population[i];
    }
    for(int i = 0; i < n; ++i){
        int num;
        cin >> num;
        for(int j = 0; j < num; ++j){
            int a;
            cin >> a;
            adj[i].push_back(a - 1);
        }
    }
    
    int ans = INT_MAX;
    
    for(int mask = 1; mask < (1 << n) - 1; ++mask) {
        vector<int> groupA, groupB;
        
        for(int i = 0; i < n; ++i) {
            if(mask & (1 << i)) groupA.push_back(i);
            else groupB.push_back(i);
        }
        
        if(bfs(groupA) && bfs(groupB)) {
            int sumA = 0, sumB = 0;
            
            for(int idx : groupA) {
                sumA += population[idx];
            }
            for(int idx : groupB) {
                sumB += population[idx];
            }
            ans = min(ans, abs(sumA - sumB));
        }
    }

    if(ans == INT_MAX) cout << -1;
    else cout << ans;
    
    return 0;
}
