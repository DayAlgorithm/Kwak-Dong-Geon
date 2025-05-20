#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = 987654321;

int n, m;
int pass[101][101]; //경유점
deque<int> path;    //경로
vector<vector<int>> adj;   

void floyd(){
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(i == j) continue;
                if(adj[i][k] + adj[k][j] < adj[i][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                    pass[i][j] = k; //경유점 저장
                }
            }
        }
    }
}

//경로 복원
void findPath(int u, int v){
    if(pass[u][v] == 0){    //경유점이 없으면 경로에 시작과 끝을 넣음
        path.push_back(u);
        path.push_back(v);
        return;
    }

    //u에서 k로 k에서 v로 가는 경로 복원
    findPath(u, pass[u][v]);
    path.pop_back();
    findPath(pass[u][v], v);
}

int main(){
    FastIO;
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1, vector<int>(n + 1, INF));
    int u, v, w;
    for(int i = 0; i < m; ++i){
        cin >> u >> v >> w;
        adj[u][v] = min(adj[u][v], w);
    }
    floyd();
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(adj[i][j] == INF) cout << 0 << " ";
            else cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j || adj[i][j] == INF){
                cout << 0 << "\n";
                continue;
            }
            findPath(i, j);
            cout << path.size() << " ";
            while(!path.empty()){
                cout << path.front() << " ";
                path.pop_front();
            }
            cout << "\n";
        }
    }
    return 0;
}