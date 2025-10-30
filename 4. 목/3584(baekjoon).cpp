#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int t;
int main() {
    FastIO;
    cin >> t;
    while(t--){
        int n;
        vector<int> edges[10001];
        cin >> n;
        for(int i = 0; i < n - 1; ++i){
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
        }
        int a, b;
        cin >> a >> b;
        vector<int> parent(n + 1, 0);
        for(int i = 1; i <= n; ++i){
            for(int e : edges[i]){
                parent[e] = i;
            }
        }
        set<int> ancestors;
        while(a != 0){
            ancestors.insert(a);
            a = parent[a];
        }
        while(b != 0){
            if(ancestors.find(b) != ancestors.end()){
                cout << b << '\n';
                break;
            }
            b = parent[b];
        }
    }
    return 0;
}
