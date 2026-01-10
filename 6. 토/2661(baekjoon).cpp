#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
string ans;

bool check(const string& s) {
    int len = s.size();
    for(int i = 1; i <= len / 2; i++) {
        if(s.substr(len - 2 * i, i) == s.substr(len - i)) {
            return false;
        }
    }
    return true;
}

bool flag;
void dfs(int len, string s) {
    if(flag) return;
    if(!check(s)) return;
    if(len == n) {
        ans = s;
        flag = true;
        return;
    }
    dfs(len + 1, s + '1');
    if(flag) return;
    dfs(len + 1, s + '2');
    if(flag) return;
    dfs(len + 1, s + '3');
}

int main() {
    FastIO;
    cin >> n;
    dfs(0, "");
    cout << ans;
    return 0;
}
