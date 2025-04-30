#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n, m;
vector<vector<int>> invest;
int comp[301][21];

int cache[301][21];
int dp(int money, int now){
    if(now == 0) return 0;

    int& ret = cache[money][now];
    if(ret != -1) return ret;
    ret = 0;

    for(int i = 0; i <= money; ++i){
        int next = dp(money - i, now - 1) + invest[i][now];
        if(ret < next){
            ret = next;
            comp[money][now] = i;
        }
    }
    return ret;
}

void printComp(int money, int now){
    if(now == 0) return;
    printComp(money - comp[money][now], now - 1);
    cout << comp[money][now] << " ";
}

int main() {
    FastIO;
    cin >> n >> m;
    invest = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
    int p;
    for(int i = 0; i < n; ++i){
        cin >> p;
        for(int j = 1; j <= m; ++j){
            cin >> invest[p][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    cout << dp(n, m) << "\n";
    printComp(n, m);
    return 0;
}