#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

string s;
int cnt[26], ans = 0;

void solve(int depth, char prev){
    if(depth == s.length()){
        ans++;
        return;
    }
    
    for(int i = 0; i < 26; i++){
        if(cnt[i] == 0) continue;
        if(prev == 'a' + i) continue;
        
        cnt[i]--;
        solve(depth + 1, 'a' + i);
        cnt[i]++;
    }
}

int main(){
    FastIO;
    cin >> s;
    for(int i = 0; i < s.length(); ++i){
        cnt[s[i] - 'a']++;
    }
    solve(0, '.');
    cout << ans;
    return 0;
}
