#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int t;

int main() {
    FastIO;
    cin >> t;
    while(t--){
        int k, m, p, ans = 0;
        int degree[1001] = {0}, strahler[1001] = {0};
        int cnt[1001] = {0};
        vector<int> graph[1001];
        queue<int> q;
        
        cin >> k >> m >> p;

        for(int i = 0; i < p; ++i){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            degree[v]++;
        }
        
        for(int i = 1; i <= m; ++i){
            if(degree[i] == 0){
                q.push(i);
                strahler[i] = 1;
            }
        }
        
        while(!q.empty()){
            int here = q.front();
            q.pop();
            
            if(cnt[here] > 1) strahler[here]++;
            ans = max(ans, strahler[here]);
            
            for(int there : graph[here]){
                if(strahler[there] < strahler[here]){
                    strahler[there] = strahler[here];
                    cnt[there] = 1;
                }
                else if(strahler[there] == strahler[here]){
                    cnt[there]++;
                }
                
                degree[there]--;
                if(degree[there] == 0){
                    q.push(there);
                }
            }
        }
        
        cout << k << " " << ans << "\n";
    }
    return 0;
}
