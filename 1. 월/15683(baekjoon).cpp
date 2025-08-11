#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};

int n, m, cnt, ans = INT_MAX;
int room[9][9];
vector<pair<int, int>> cctv;

void states(int y, int x, int dir){
    int ny = y + dy[dir % 4], nx = x + dx[dir % 4];
    while(true){
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || room[ny][nx] == 6) break;
        if(!room[ny][nx]) room[ny][nx] = -1;
        ny += dy[dir % 4]; nx += dx[dir % 4];
    }
}

void calcSum(){
    int sum = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!room[i][j]) sum++;
        }
    }
    ans = min(ans, sum);
}

void watch(int idx){
    if(idx == cnt){
        calcSum();
        return;
    }

    int y = cctv[idx].first, x = cctv[idx].second;
    int temp[9][9];
    for(int d = 0; d < 4; ++d){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                temp[i][j] = room[i][j];
            }
        }
        if(room[y][x] == 1){
            states(y, x, d);
        }
        else if(room[y][x] == 2){
            states(y, x, d);
            states(y, x, d + 2);
        }
        else if(room[y][x] == 3){
            states(y, x, d);
            states(y, x, d + 1);
        }
        else if(room[y][x] == 4){
            states(y, x, d);
            states(y, x, d + 1);
            states(y, x, d + 2);
        }
        else {
            states(y, x, d);
            states(y, x, d + 1);
            states(y, x, d + 2);
            states(y, x, d + 3);
        }
        watch(idx + 1);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                room[i][j] = temp[i][j];
            }
        }
    }
}

int main() {
    FastIO;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0;  j < m; ++j){
            cin >> room[i][j];
            if(room[i][j] && room[i][j] != 6){
                cctv.push_back({i, j});
                cnt++;
            }
        }
    }
    watch(0);
    cout << ans;
    return 0;
}