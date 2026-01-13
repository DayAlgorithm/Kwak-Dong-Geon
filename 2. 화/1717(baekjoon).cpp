#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m;
int parent[1000001];

int findParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

void unionSets(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a == b) return;
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

bool check(int a, int b){
    return findParent(a) == findParent(b);
}

int main() {
    FastIO;
    cin >> n >> m;
    for(int i = 0; i <= n; i++) parent[i] = i;
    for(int i = 0; i < m; i++) {
        int o, a, b;
        cin >> o >> a >> b;
        if(!o) {
            unionSets(a, b);
        }
        else {
            if(check(a, b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
