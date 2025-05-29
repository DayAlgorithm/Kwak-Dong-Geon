#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n;

long long cache[31][31];
long long cnt(int idx, int cntW, int cntH){
    if(idx == 2 * n) return 1;

    long long& ret = cache[cntW][cntH];
    if(ret != -1) return ret;
    ret = 0;
    if(cntW) ret += cnt(idx + 1, cntW - 1, cntH + 1);
    if(cntH) ret += cnt(idx + 1, cntW, cntH - 1);
    return ret;
}

int main(){
    FastIO;
    memset(cache, -1, sizeof(cache));
    while(true){
        cin >> n;
        if(!n) break;
        int cntW = n, cntH = 0;
        cout << cnt(0, cntW, cntH) << "\n";
    }    
    return 0;
}