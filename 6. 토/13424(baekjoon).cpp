#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int t, n, m, k;
int adj[101][101];
vector<int> friends;

void floyd(){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(adj[i][k] != INT_MAX && adj[k][j] != INT_MAX){
                    if(adj[i][j] > adj[i][k] + adj[k][j]){
                        adj[i][j] = adj[i][k] + adj[k][j];
                    }
                }
            }
        }
    }
}


int main(){
    FastIO;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) adj[i][j] = 0;
                else adj[i][j] = INT_MAX;
            }
        }
        for(int i = 0; i < m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a][b] = c;
            adj[b][a] = c;
        }
        floyd();
        cin >> k;
        friends.clear();
        for(int i = 0; i < k; i++){
            int a;
            cin >> a;
            friends.push_back(a);
        }
        int minSum = INT_MAX, ans;
        for(int i = 1; i <= n; i++){
            int sum = 0;
            for(auto f : friends){
                sum += adj[i][f];
            }
            if(minSum > sum){
                minSum = sum;
                ans = i;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}