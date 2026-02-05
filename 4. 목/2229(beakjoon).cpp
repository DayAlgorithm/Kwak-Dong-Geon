#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n, score[1002];

int cache[1002];
int dp (int idx) {
    if(idx == n) return 0;
    
    int &ret = cache[idx];
    if (ret != -1) return ret;

    int maxS = 0, minS = 10000;
    for (int i = idx; i < n; i++) {
        if (score[i] > maxS) maxS = score[i];
        if (score[i] < minS) minS = score[i];

        ret = max(ret, dp(i + 1) + maxS - minS);
    }
    
    return ret;
}

int main() { 
    FastIO;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> score[i];
    }
    memset(cache, -1, sizeof(cache));
    cout << dp(0);
    return 0; 
}