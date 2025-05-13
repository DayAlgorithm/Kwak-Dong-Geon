#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {1, -1, 0, 0};

int n, east, west, south, north;
double total, simple;
double prob[4];

bool visited[30][30];
double dfs(int y, int x, int cnt) {
    if (cnt == n) return 1;

    double ret = 0;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i], nx = x + dx[i];
        if (visited[ny][nx]) continue;
        visited[ny][nx] = true;
        //단순 경로에 대한 확률 계산산
        ret += prob[i] * dfs(ny, nx, cnt + 1);
        visited[ny][nx] = false;    //백트레킹킹
    }
    return ret;
}

int main(){
    FastIO;
    cin >> n;
    cin >> east >> west >> south >> north;
    //각 방향에 대한 확률 계산산
    prob[0] = east / 100.0;
    prob[1] = west / 100.0;
    prob[2] = south / 100.0;
    prob[3] = north / 100.0;
    visited[15][15] = 1;
    cout.precision(10);
    cout << fixed << dfs(15, 15, 0);
    return 0;
}