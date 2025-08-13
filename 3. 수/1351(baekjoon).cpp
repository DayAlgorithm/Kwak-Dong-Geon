#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

long long n, p, q;
unordered_map<long long, long long> cache;

long long dp(long long i) {
    if(!i) return 1;
    if(cache.count(i)) return cache[i];
    return cache[i] = dp(i / p) + dp(i / q);
}

int main(){
    FastIO;
    cin >> n >> p >> q;
    cout << dp(n);
    return 0;
}