#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int INF = 987654321;

int n, t;
int cache[102][10001];
int num[102][2];

int score(int idx, int time){
    if(time == t || idx == n) return 0;

    int &ret = cache[idx][time];
    if(ret != -1) return ret;

    if(time + num[idx][0] <= t){
        ret = max(ret, score(idx + 1, time + num[idx][0]) + num[idx][1]);
    }
    ret = max(ret, score(idx + 1, time));
    
    return ret;
}

int main() { 
    FastIO;
    cin >> n >> t;
    memset(cache, -1, sizeof(cache));
    for(int i = 0; i < n; i++){
        cin >> num[i][0] >> num[i][1];
    }
    cout << score(0, 0);
    return 0; 
}
