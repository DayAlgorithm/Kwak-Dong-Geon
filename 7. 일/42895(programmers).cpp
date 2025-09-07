#include <bits/stdc++.h>
using namespace std;

int num, n;
map<long long, int> cache[9];

int dp(int cnt, int now){
    if(cnt > 8) return INT_MAX;
    if(now == num) return cnt;
    
    
    if(cache[cnt].find(now) != cache[cnt].end()) return cache[cnt][now];
    
    int& ret = cache[cnt][now];
    ret = INT_MAX;
    int next = 0;
    for(int i = 0; cnt + i < 9; ++i){
        next = next * 10 + n;
        ret = min(ret, dp(cnt + 1 + i, now + next));
        ret = min(ret, dp(cnt + 1 + i, now - next));
        ret = min(ret, dp(cnt + 1 + i, now * next));
        ret = min(ret, dp(cnt + 1 + i, now / next));
    }
    return ret;
}
int solution(int N, int number) {
    n = N; num = number;
    int ans = dp(0, 0);
    if(ans == INT_MAX) ans = -1;
    return ans;
}
