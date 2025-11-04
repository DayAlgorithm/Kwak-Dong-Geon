#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
long long x;
long long layer[51], patty[51];
long long solve(int level, long long x){
    if(level == 0) return x > 0 ? 1 : 0;
    if(x <= 0) return 0;
    
    if(x >= layer[level]) return patty[level];
    if(x == 1) return 0;
    
    if(x <= 1 + layer[level - 1]) return solve(level - 1, x - 1);
    if(x == 1 + layer[level - 1] + 1) return patty[level - 1] + 1;
    if(x < layer[level] - 1) return patty[level - 1] + 1 + solve(level - 1, x - 1 - layer[level - 1] - 1);
    
    return patty[level] - 0;
}

int main(){
    FastIO;
    cin >> n >> x;
    
    layer[0] = 1;
    patty[0] = 1;

    for(int i = 1; i <= n; ++i){
        layer[i] = 1 + layer[i - 1] + 1 + layer[i - 1] + 1;
        patty[i] = patty[i - 1] + 1 + patty[i - 1];
    }
    
    cout << solve(n, x);
    return 0;
}
