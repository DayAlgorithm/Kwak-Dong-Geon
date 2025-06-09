#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int s, board[4][4];
bool flag, win;

int main(){
    FastIO;
    cin >> s;
    if(s == 2) flag = true;
    int x, y;
    while(cin >> x >> y){
        if(flag){
            board[x][y] = 2;
            flag = false;
        }
        else{
            board[x][y] = 1;
            flag = true;
        }
        if(board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3]){
            win = true;
            if(board[1][1] == 1) flag = false;
            else flag = true;
            break;
        }
        if(board[1][3] && board[1][3] == board[2][2] && board[2][2] == board[3][1]){
            win = true;
            if(board[1][3] == 1) flag = false;
            else flag = true;
            break;
        }
        if(board[1][1] && board[1][1] == board[1][2] && board[1][2] == board[1][3]){
            win = true;
            if(board[1][1] == 1) flag = false;
            else flag = true;
            break;
        }
        if(board[2][1] && board[2][1] == board[2][2] && board[2][2] == board[2][3]){
            win = true;
            if(board[2][1] == 1) flag = false;
            else flag = true;
            break;
        }
        if(board[3][1] && board[3][1] == board[3][2] && board[3][2] == board[3][3]){
            win = true;
            if(board[3][1] == 1) flag = false;
            else flag = true;
            break;
        }
        if(board[1][1] && board[1][1] == board[2][1] && board[2][1] == board[3][1]){
            win = true;
            if(board[1][1] == 1) flag = false;
            else flag = true;
            break;
        }
        if(board[1][2] && board[1][2] == board[2][2] && board[2][2] == board[3][2]){
            win = true;
            if(board[1][2] == 1) flag = false;
            else flag = true;
            break;
        }
        if(board[1][3] && board[1][3] == board[2][3] && board[2][3] == board[3][3]){
            win = true;
            if(board[1][3] == 1) flag = false;
            else flag = true;
            break;
        }
    }
    if(win){
        if(flag) cout << 2;
        else cout << 1;
    }
    else cout << 0;
    return 0;
}