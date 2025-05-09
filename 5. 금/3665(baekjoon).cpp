#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int t;
vector<int> ans;

bool bfs(int n, vector<set<int>>& adj, vector<int>& degreeIn){
    queue<int> q;
    for(int i = 1; i <= n; ++i){
        if(!degreeIn[i]) q.push(i); 
    }
    while(!q.empty()){
        if(q.size() != 1) return false;
        int here = q.front();
        q.pop();
        ans.push_back(here);
        for(auto& there : adj[here]){
            degreeIn[there]--;
            if(!degreeIn[there]){
                q.push(there);
            }
        }
    }
    return true;
}

void makeTree(int n, vector<set<int>>& adj, vector<int>& lastYear, vector<int>& degreeIn){
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            adj[lastYear[i]].insert(lastYear[j]);
            degreeIn[lastYear[j]]++;
        }
    }
}

int main(){
    FastIO;
    cin >> t;
    while(t--){
        ans.clear();
        int n, c;
        cin >> n;
        vector<int> rank(n + 1);    //작년 등수
        vector<set<int>> adj(n + 1);    //그래프
        vector<int> degreeIn(n + 1);    //각 노드에 들어가는 차수
        vector<int> lastYear(n);    //작년 순위
        for(int i = 0; i < n; ++i){
            cin >> lastYear[i];
            rank[lastYear[i]] = i;
        }
        makeTree(n, adj, lastYear, degreeIn);
        cin >> c;
        int a, b;
        for(int i = 0; i < c; ++i){
            cin >> a >> b;
            if(adj[a].count(b)){    //a가 b보다 등수가 높았던 경우
                adj[a].erase(b); 
                degreeIn[b]--;
                adj[b].insert(a); 
                degreeIn[a]++;
            } 
            else{   //b가 a보다 등수가 높았던 경우
                adj[b].erase(a); 
                degreeIn[a]--;
                adj[a].insert(b); 
                degreeIn[b]++;
            }
        }
        if(bfs(n, adj, degreeIn)){
            if(ans.size() != n) cout << "IMPOSSIBLE";
            else {
                for(int i = 0; i < n; ++i){
                    cout << ans[i] << " ";
                }
            }
        } 
        else cout << "?";
        cout << "\n";
    }
    return 0;
}