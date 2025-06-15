#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int c, r, k;
bool board[1001][1001];

int main(){
    FastIO;
    cin >> c >> r >> k;
    if(c * r < k) cout << 0;
    else if(k == 1) cout << 1 << ' ' << 1;
    else{
        int x = 1, y = 1, dir = 0, cnt = 1;
        board[x][y]=true;
        while(true){
            int nx= x + dx[dir], ny = y + dy[dir];
            if(ny > r || ny <= 0 || nx > c || nx <= 0 || board[nx][ny]) dir = (dir + 1) % 4;
            x += dx[dir]; y += dy[dir];
            board[x][y] = true;
            cnt++;
            if(cnt==k) break;
        }
        cout << x << ' ' << y;
    }
    return 0;
}