#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n;
int board[101][101];

long long cache[101][101];
long long dp(int r, int c) {
    if(r == n - 1 && c == n - 1) return 1;
    if(r >= n || c >= n) return 0;

    long long &ret = cache[r][c];
    if(ret != -1) return ret;

    ret = 0;
    ret += dp(r + board[r][c], c) + dp(r, c + board[r][c]);
    return ret;
}

int main() { 
    FastIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    cout << dp(0, 0);
    return 0; 
}