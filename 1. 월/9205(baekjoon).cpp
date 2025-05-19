#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int t, n, startX, startY, endX, endY;
vector<pair<int, int>> store;

bool visited[101];
bool walk(){
    queue<pair<int, int>> q;
    q.push({startX, startY});
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        //도착 가능하면 true 반환
        if(abs(endX - x) + abs(endY - y) <= 1000) return true;
        for(int i = 0; i < n; ++i){
            if(visited[i]) continue;
            int nx = store[i].first, ny = store[i].second;
            if(abs(nx - x) + abs(ny - y) <= 1000){  //이동 가능한 편의점으로 이동
                visited[i] = true;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

int main(){
    FastIO;
    cin >> t;
    while(t--){
        cin >> n;
        store = vector<pair<int, int>>(n);
        cin >> startX >> startY;
        for(int i = 0; i < n; ++i){
            cin >> store[i].first >> store[i].second;
        }
        cin >> endX >> endY;
        //테스트 케이스마다 방문 초기화
        memset(visited, false, sizeof(visited));
        if(walk()) cout << "happy\n";
        else cout << "sad\n";
    }    
    return 0;
}