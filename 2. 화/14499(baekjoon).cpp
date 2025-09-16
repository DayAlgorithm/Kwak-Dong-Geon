#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int dx[] = {0, 0, 0, -1, 1};
const int dy[] = {0, 1, -1, 0, 0};

int n, m, x, y, k;
int board[21][21];
int dice[6];

void move(int order){
    int nx = x + dx[order], ny = y + dy[order];
    if(nx < 0 || nx >= n || ny < 0 || ny >= m) return;
    int tmp = dice[0];
    if(order == 1){
        dice[0] = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[2];
        dice[2] = tmp;
    }
    else if(order == 2){
        dice[0] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[3];
        dice[3] = tmp;
    }
    else if(order == 3){
        dice[0] = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[5];
        dice[5] = tmp;
    }
    else if(order == 4){
        dice[0] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[4];
        dice[4] = tmp;
    }

    x = nx; y = ny;
    if(!board[x][y]){
        board[x][y] = dice[1];
    }
    else {
        dice[1] = board[x][y];
        board[x][y] = 0;
    }
    cout << dice[0] << "\n";
}

int main() {
    FastIO;
    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> board[i][j];
        }
    }
    int order;
    for(int i = 0; i < k; ++i){
        cin >> order;
        move(order);
    }
    return 0;
}