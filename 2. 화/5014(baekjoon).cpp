#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int f, s, g, u, d;

int bfs(){
    set<int> visited;
    queue<pair<int, int>> q;
    q.push({s, 0});
    visited.insert(s);
    while(!q.empty()){
        int here = q.front().first, cnt = q.front().second;
        q.pop();

        if(here == g) return cnt;
        int up = here + u, down = here - d;
        if(up <= f && visited.find(up) == visited.end()){
            visited.insert(up);
            q.push({up, cnt + 1});
        }
        if(down >= 1 && visited.find(down) == visited.end()){
            visited.insert(down);
            q.push({down, cnt + 1});
        }
    }
    return -1;
}

int main() {
    FastIO;
    cin >> f >> s >> g >> u >> d;
    int ans = bfs();
    if(ans == -1) cout << "use the stairs";
    else cout << ans;
    return 0;
}
