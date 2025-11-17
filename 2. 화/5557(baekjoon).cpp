#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n;
vector<int> arr;

long long cache[101][21];
long long dp(int idx, int calc){
    if(idx == n - 2){
        if(calc == arr[n - 1]) return 1;
        else return 0;
    }
    if(calc > 20 || calc < 0) return 0;

    long long& ret = cache[idx][calc];
    if(ret != -1) return ret;
    ret = 0;
    ret += dp(idx + 1, calc + arr[idx + 1]);
    ret += dp(idx + 1, calc - arr[idx + 1]);
    return ret;
}

int main(){
    FastIO;
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    memset(cache, -1, sizeof(cache));
    cout << dp(0, arr[0]) << '\n';
    return 0;
}