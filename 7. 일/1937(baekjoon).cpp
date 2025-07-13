#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const int INF = INT_MAX;

int n, M = 0;
int num[502][502];

int cache[501][501];
int dp(int x, int y){
    if (num[x + 1][y] <= num[x][y] && num[x][y + 1] <= num[x][y] 
        && num[x - 1][y] <= num[x][y] && num[x][y - 1] <= num[x][y])
        return 0;

    int &ret = cache[x][y];
    if(ret != -1) return ret;
    
    ret = -INF;

    if(num[x + 1][y] > num[x][y]){
        ret = max(ret, dp(x + 1, y) + 1);
    }
    if(num[x][y + 1] > num[x][y]){
        ret = max(ret, dp(x, y + 1) + 1);
    }
    if(num[x - 1][y] > num[x][y]){
        ret = max(ret, dp(x - 1, y) + 1);
    }
    if(num[x][y - 1] > num[x][y]){
        ret = max(ret, dp(x, y - 1) + 1);
    }

    return ret;
}

int main(){
    FastIO;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> num[i][j];
        }
    }

    memset(cache, -1, sizeof(cache));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(dp(i, j) > M) M = dp(i, j);
        }
    }
    cout << M + 1;
    return 0;
}