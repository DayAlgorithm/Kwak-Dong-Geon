#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, t, ans = -1;
vector<pair<int,int>> hold;
map<pair<int, int>, bool> visited;

struct node {
    int x;
    int y;
    int cnt;
};

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

queue<node> q;
void bfs(){
    q.push({0, 0, 0});

    while(!q.empty()) {
        int x = q.front().x, y = q.front().y, cnt = q.front().cnt;
        q.pop();

        if(y==t){
            ans = cnt;
            return;
        }

        if(visited[{x, y}]) continue;
        visited[{x, y}]=true;

        auto it = lower_bound(hold.begin(), hold.end(), pair<int,int>(0, y - 2), cmp) - hold.begin();
        
        for(int i = it; i < hold.size() && abs(hold[i].second - y) <= 2; ++i){
            int nx=hold[i].first, ny=hold[i].second;
            if(!visited[{nx, ny}] && abs(nx - x) <= 2) q.push({nx, ny, cnt + 1});
        }
    }
    return;
}

int main() {
    FastIO;
    cin >> n >> t;
    
    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        hold.push_back({x, y});
        visited[{x, y}]=false;
    }
    
    sort(hold.begin(), hold.end(), cmp);
    bfs();
    cout << ans;
}