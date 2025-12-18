#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int t;
int n, k;
int parent[1000001];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) parent[a] = b;
}

int main() {
    FastIO;
    cin >> t;
    
    for(int T = 1; T <= t; T++) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for(int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            unite(a, b);
        }
        
        int m;
        cin >> m;

        cout << "Scenario " << T << ":\n";
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            if(find(u) == find(v)) cout << "1\n";
            else cout << "0\n";
        }
        cout << "\n";
    }
    
    return 0;
}
