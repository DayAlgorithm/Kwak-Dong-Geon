#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;


int n, m;
int adj[201][201];
vector<int> path;
int parent[201];


int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}


void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    parent[b] = a;
}


int main() {
    FastIO;
    cin >> n >> m;
    
    for(int i = 1; i <= n; ++i){
        parent[i] = i;
    }
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> adj[i][j];
            if(adj[i][j] == 1){
                unite(i, j);
            }
        }
    }
    
    path.resize(m);
    for(int i = 0; i < m; ++i){
        cin >> path[i];
    }
    
    bool possible = true;
    for(int i = 0; i < m - 1; ++i){
        if(find(path[i]) != find(path[i + 1])){
            possible = false;
            break;
        }
    }
    
    if(possible) cout << "YES";
    else cout << "NO";
    
    return 0;
}
