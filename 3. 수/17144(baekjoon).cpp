#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};

int r, c, t;
int board[51][51];

vector<int> air;

//먼지 확산산
void dust_move(){
    int temp[51][51] = {0, };   //확산 된 먼지 저장장
    temp[air[0]][0] = -1;
    temp[air[1]][0] = -1;
    //보드 순회회
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(board[i][j] <= 0) continue;
            int dust = board[i][j] / 5;
            int cnt = 0;
            for(int k = 0; k < 4; ++k){
                int ny = i + dy[k], nx = j + dx[k];
                if(ny >= 0 && ny < r && nx >= 0 && nx < c && board[ny][nx] != -1){
                    temp[ny][nx] += dust;
                    cnt++;  //확산 성공한 먼지 개수 
                }
            }
            temp[i][j] += (board[i][j] - dust * cnt);
        }
    }
    memcpy(board, temp, sizeof(temp));  //보드에 복사사
}

void clear_air(){
    //위에 영역 공기 이동동
    int up = air[0];
    for(int i = up - 1; i > 0; --i){
        board[i][0] = board[i - 1][0];
    }
    for(int i = 0; i < c - 1; ++i){
        board[0][i] = board[0][i + 1];
    }
    for(int i = 0; i < up; ++i){
        board[i][c-1] = board[i + 1][c - 1];
    }
    for(int i = c - 1; i > 1; --i){
        board[up][i] = board[up][i - 1];
    }
    board[up][1] = 0;
    
    //아래 영역 공기 이동동
    int down = air[1];
    for(int i = down + 1; i < r - 1; ++i){
        board[i][0] = board[i + 1][0];
    }
    for(int i = 0; i < c - 1; ++i){
        board[r - 1][i] = board[r - 1][i + 1];
    }
    for(int i = r - 1; i > down; --i){
        board[i][c - 1] = board[i - 1][c - 1];
    }
    for(int i = c - 1; i > 1; --i){
        board[down][i] = board[down][i - 1];
    }
    board[down][1] = 0;
}

int solve(){
    int ret = 0;
    while(t--){
        dust_move();
        clear_air();
    }
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if(board[i][j] > 0){
                ret += board[i][j];
            }
        }
    }
    return ret;
}

int main(){
    FastIO;
    cin >> r >> c >> t;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            cin >> board[i][j];
            if(board[i][j] == -1) air.push_back(i);
        }
    }
    cout << solve();
    return 0;
}