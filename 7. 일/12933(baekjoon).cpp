#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

string s;
int ans;

int idx(char c) {
    if (c == 'q') return 0;
    if (c == 'u') return 1;
    if (c == 'a') return 2;
    if (c == 'c') return 3;
    if (c == 'k') return 4;
    return -1;
}

int main() {
    FastIO;
    cin >> s;

    int cnt[5] = {0, 0, 0, 0, 0};
    ans = 0;

    for(auto c : s) {
        int t = idx(c);
        if(t == -1) {
            cout << -1;
            return 0;
        }

        if(t == 0) {
            if(cnt[4] > 0) cnt[4]--;
            cnt[0]++;
        } 
        else {
            if(cnt[t - 1] == 0) {
                cout << -1;
                return 0;
            }
            cnt[t - 1]--;
            cnt[t]++;
        }

        int now = cnt[0] + cnt[1] + cnt[2] + cnt[3];
        ans = max(ans, now);
    }

    if(cnt[0] != 0 || cnt[1] != 0 || cnt[2] != 0 || cnt[3] != 0 || ans == 0) cout << -1;
    else cout << ans;
    return 0;
}