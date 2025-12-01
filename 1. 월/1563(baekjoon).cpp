#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
int cache[1001][3][4][3];

int dp(int idx, int cnt, int row, int before){
    if(cnt == 2 || row == 3) return 0;
    if(idx == n) return 1;

    int &ret = cache[idx][cnt][row][before];
    if(ret != -1) return ret;
    ret = 0;

    ret += dp(idx + 1, cnt, 0, 0) % 1000000;
    ret += dp(idx + 1, cnt + 1, 0, 1) % 1000000;
    if(before == 2)ret += dp(idx + 1, cnt, row + 1, 2) % 1000000;
    else ret += dp(idx + 1, cnt, 1, 2) % 1000000;

    return ret % 1000000;
}

int main() { 
    FastIO;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    cout << dp(0, 0, 0, 0);
    return 0; 
}