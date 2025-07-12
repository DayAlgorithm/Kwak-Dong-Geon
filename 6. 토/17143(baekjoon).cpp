#include<bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int dy[] = {0, -1, 1, 0, 0};
const int dx[] = {0, 0, 0, 1, -1};

struct Shark {
    int y, x, s, d, z;
    bool flag;
};

int r, c, m;
vector<Shark> sharks;
int board[101][101];

int main(){
    FastIO;
    cin >> r >> c >> m;
    sharks.resize(m);
    memset(board, -1, sizeof(board));
    for(int i = 0; i < m; ++i){
        int y, x, s, d, z;
        cin >> y >> x >> s >> d >> z;
        --y; --x;
        sharks[i] = {y, x, s, d, z, true};
        board[y][x] = i;
    }

    int ans = 0;
    for(int king = 0; king < c; ++king) {
        for(int y = 0; y < r; ++y) {
            int idx = board[y][king];
            if(idx != -1 && sharks[idx].flag) {
                ans += sharks[idx].z;
                sharks[idx].flag = false;
                board[y][king] = -1;
                break;
            }
        }

        int temp[101][101];
        memset(temp, -1, sizeof(temp));
        for(int i = 0; i < m; ++i){
            if(!sharks[i].flag) continue;
            int y = sharks[i].y;
            int x = sharks[i].x;
            int s = sharks[i].s;
            int d = sharks[i].d;

            int move = s;
            if(d == 1 || d == 2) move %= (2 * (r - 1));
            else move %= (2 * (c - 1));

            for(int j = 0; j < move; ++j) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if(ny < 0 || ny >= r || nx < 0 || nx >= c) {
                    if(d == 1) d = 2;
                    else if(d == 2) d = 1;
                    else if(d == 3) d = 4;
                    else if(d == 4) d = 3;
                    ny = y + dy[d];
                    nx = x + dx[d];
                }
                y = ny;
                x = nx;
            }
            sharks[i].y = y;
            sharks[i].x = x;
            sharks[i].d = d;

            if(temp[y][x] == -1) temp[y][x] = i;
            else{
                int pre = temp[y][x];
                if(sharks[pre].z < sharks[i].z){
                    sharks[pre].flag = false;
                    temp[y][x] = i;
                } 
                else {
                    sharks[i].flag = false;
                }
            }
        }
        memcpy(board, temp, sizeof(board));
    }
    cout << ans << '\n';
    return 0;
}
