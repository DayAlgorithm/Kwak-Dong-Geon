#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m, k;
bool know[51];
vector<int> party[51];
int parent[51];

int Find(int x){
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b){
    a = Find(a); b = Find(b);
    if(a != b) parent[b] = a;
}

int main() {
    FastIO;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) parent[i] = i;

    for(int i = 0; i < k; ++i){
        int num; 
        cin >> num;
        know[num] = true;
    }

    for(int i = 0; i < m; ++i){
        int t; 
        cin >> t;
        for(int j = 0; j < t; ++j){
            int num; 
            cin >> num;
            party[i].emplace_back(num);
        }

        for(int j = 1; j < t; ++j){
            Union(party[i][j - 1], party[i][j]);
        }
    }

    int truthRoot = -1;
    for(int i = 1; i <= n; ++i){
        if(know[i]){
            if(truthRoot == -1) truthRoot = Find(i);
            else Union(truthRoot, i);
        }
    }
    if(truthRoot == -1) truthRoot = 0;

    int ans = 0;
    for(int i = 0; i < m; ++i){
        bool flag = true;
        for(auto p : party[i]){
            if(Find(p) == truthRoot){
                flag = false;
                break;
            }
        }
        if(flag) ++ans;
    }

    cout << ans;
    return 0;
}
