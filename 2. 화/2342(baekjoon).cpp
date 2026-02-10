#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int i;
int ddr[100000];
int cache[100000][5][5];

int dp(int idx, int x, int y) {
    if (x == y && x != 0) return 987654321;
    if (idx == i) return 0;

    int &ret = cache[idx][x][y];
    if (ret != -1) return ret;
    
    ret = 987654321;
    if (x == ddr[idx] || y == ddr[idx]) ret = min(ret, dp(idx + 1, x, y) + 1);
    if (abs(x - ddr[idx]) == 2 && x != 0) ret = min(ret, dp(idx + 1, ddr[idx], y) + 4);
    if (abs(y - ddr[idx]) == 2 && y != 0) ret = min(ret, dp(idx + 1, x, ddr[idx]) + 4);
    if (abs(x - ddr[idx]) != 2 && x != 0) ret = min(ret, dp(idx + 1, ddr[idx], y) + 3);
    if (abs(y - ddr[idx]) != 2 && y != 0) ret = min(ret, dp(idx + 1, x, ddr[idx]) + 3);
    if (!x) ret = min(ret, dp(idx + 1, ddr[idx], y) + 2);
    if (!y) ret = min(ret, dp(idx + 1, x, ddr[idx]) + 2);

    return ret;
}

int main() {
    FastIO;
    while (true) {
        int n;
        cin >> n;
        if (!n) break;
        ddr[i] = n;
        i++;
    }
    memset(cache, -1, sizeof(cache));
    cout << dp(0, 0, 0);
    return 0;
}