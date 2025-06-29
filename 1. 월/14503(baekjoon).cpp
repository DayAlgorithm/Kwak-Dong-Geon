#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int n, m, r, c, d;
int room[50][50];

int clean(){
    int ret = 0;
    while(true){
        if(!room[r][c]) {
            room[r][c] = -1;
            ret++;
        }
        bool flag = false;
        int ny = 0, nx = 0;
        for(int i = 0; i < 4; ++i){
            ny = r + dy[i]; nx = c + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(!room[ny][nx]) flag = true;
        }
        
        if(!flag){
            ny = r + dy[(d + 2) % 4]; nx = c + dx[(d + 2) % 4];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || room[ny][nx] == 1) break;
            
        } 
        else {
            d = (d + 3) % 4;
            ny = r + dy[d]; nx = c + dx[d];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || room[ny][nx] == 1 || room[ny][nx] == -1) continue;
        }
        r = ny; c = nx;
    }
    return ret;
}

int main() {
    FastIO;
    cin >> n >> m >> r >> c >> d;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> room[i][j];
        }
    }
    cout << clean();
    return 0;
}
