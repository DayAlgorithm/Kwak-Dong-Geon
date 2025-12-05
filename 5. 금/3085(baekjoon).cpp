#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
char board[51][51];

int check() {
    int ret = 0, cnt;

    for(int i = 0; i < n; i++){
        cnt = 1;
        for(int j = 1; j < n; j++){
            if(board[i][j] == board[i][j - 1]) cnt++;
            else{
                ret = max(ret, cnt);
                cnt = 1;
            }
        }
        ret = max(ret, cnt);
    }

    for(int j = 0; j < n; j++){
        cnt = 1;
        for(int i = 1; i < n; i++){
            if(board[i][j] == board[i - 1][j]) cnt++;
            else {
                ret = max(ret, cnt);
                cnt = 1;
            }
        }
        ret = max(ret, cnt);
    }

    return ret;
}

int main() {
    FastIO;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j + 1 < n){
                swap(board[i][j], board[i][j + 1]);
                ans = max(ans, check());
                swap(board[i][j], board[i][j + 1]);
            }
            if(i + 1 < n){
                swap(board[i][j], board[i + 1][j]);
                ans = max(ans, check());
                swap(board[i][j], board[i + 1][j]);
            }
        }
    }

    cout << ans;

    return 0;
}