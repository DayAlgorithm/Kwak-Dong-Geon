#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, board[17][17], cnt;

void shiftPipe(int y, int x, int pos){
    board[y][x]++;
    if(pos == 0 || pos == 2){
		if(x < n && board[y][x + 1] != -1) shiftPipe(y, x + 1, 0);
	}
	if(pos == 1 || pos == 2){
		if(y < n && board[y + 1][x] != -1) shiftPipe(y + 1, x, 1);
	}
	if(y < n && x < n && board[y][x + 1] != -1 && board[y + 1][x] != -1 && board[y + 1][x + 1] != -1){
        shiftPipe(y + 1, x + 1, 2);
    }
}

int main() {
    FastIO;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> board[i][j];
            if(board[i][j]) board[i][j] = -1;
        }
    }
    shiftPipe(1, 2, 0);
    if(board[n][n] == -1) board[n][n] = 0;
    cout << board[n][n] << "\n";
    return 0;
}

