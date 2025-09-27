#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m;
long long rec[51][51], sum[51][51];

long long recSum(int x1, int y1, int x2, int y2){
    if(x1 > x2 || y1 > y2) return 0;
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

int main(){
    FastIO;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        string line;
        cin >> line;
        for(int j = 1; j <= m; ++j){
            rec[i][j] = line[j - 1] - '0';
            sum[i][j] = rec[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    long long ans = 0, r1, r2, r3;
    for(int i = 1; i <= m - 2; ++i){
        for(int j = i + 1; j <= m - 1; ++j){
            r1 = recSum(1, 1, n, i);
            r2 = recSum(1, i + 1, n, j);
            r3 = recSum(1, j + 1, n, m);
            ans = max(ans, r1*r2*r3);
        }
    }

    for(int i = 1; i <= n - 2; ++i){
        for(int j = i + 1; j <= n - 1; ++j){
            r1 = recSum(1, 1, i, m);
            r2 = recSum(i + 1, 1, j, m);
            r3 = recSum(j + 1, 1, n, m);
            ans = max(ans, r1*r2*r3);
        }
    }

    for(int i = 1; i <= m - 1; ++i){
        for(int j = 1; j <= n - 1; ++j){
            r1 = recSum(1, 1, n, i);
            r2 = recSum(1, i + 1, j, m);
            r3 = recSum(j + 1, i + 1, n, m);
            ans = max(ans, r1*r2*r3);
        }
    }

    for(int i = 1; i <= n - 1; ++i){
        for(int j = 1; j <= m - 1; ++j){
            r1 = recSum(1, 1, i, m);
            r2 = recSum(i + 1, 1, n, j);
            r3 = recSum(i + 1, j + 1, n, m);
            ans = max(ans, r1*r2*r3);
        }
    }

    for(int i = 1; i <= m - 1; ++i){
        for(int j = 1; j <= n - 1; ++j){
            r1 = recSum(1, 1, j, i);
            r2 = recSum(j + 1, 1, n, i);
            r3 = recSum(1, i + 1, n, m);
            ans = max(ans, r1*r2*r3);
        }
    }

    for(int i = 1; i <= n - 1; ++i){
        for(int j = 1; j <= m - 1; ++j){
            r1 = recSum(1, 1, i, j);
            r2 = recSum(1, j + 1, i, m);
            r3 = recSum(i + 1, 1, n, m);
            ans = max(ans, r1*r2*r3);
        }
    }

    cout << ans;
    return 0;
}