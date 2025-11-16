#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n, m;
long long dist[502];
bool in_queue[502];
int cycle[502];
vector<pair<int, int>> edge[502];
queue<int> q;

int main(){
    FastIO;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].emplace_back(c, b);
    }
    fill(dist, dist + n + 1, INT_MAX);
    dist[1] = 0;
    q.push(1);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        in_queue[cur] = false;
        for(pair<int, int>& i: edge[cur]){
            if(dist[i.second] > dist[cur] + i.first){
                dist[i.second] = dist[cur] + i.first;
                if(!in_queue[i.second]){
                    cycle[i.second]++;
                    if(cycle[i.second] >= n){
                        cout << -1;
                        return 0;
                    }
                    q.push(i.second);
                    in_queue[i.second] = true;
                }
            }
        }
    }
    for(int i = 2; i <= n; i++){
        if(dist[i] == INT_MAX) cout << -1 << "\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}