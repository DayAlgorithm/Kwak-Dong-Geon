#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int k;

int main() {
    FastIO;
    cin >> k;
    while(k--){
        int v, e;
        cin >> v >> e;
        vector<int> adj[v + 1];
        for(int i = 0; i < e; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> visited(v + 1, 0);
        bool flag = true;
        for(int i = 1; i <= v; i++){
            if(!visited[i]){
                queue<int> q;
                q.push(i);
                visited[i] = 1;

                while(!q.empty()){
                    int here = q.front();
                    q.pop();
                    for(int there : adj[here]){
                        if(!visited[there]){
                            visited[there] = 3 - visited[here];
                            q.push(there);
                        }
                        else if(visited[there] == visited[here]){
                            flag = false;
                            break;
                        }
                    }
                    if(!flag) break;
                }
            }
            if(!flag) break;
        }

        if(flag) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}