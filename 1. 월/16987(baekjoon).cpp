#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
vector<pair<int, int>> eggs;
int ans = 0;

void hit(int idx) {
    if(idx == n) {
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(eggs[i].first <= 0) cnt++;
        }
        ans = max(ans, cnt);
        return;
    }

    if(eggs[idx].first <= 0) {
        hit(idx + 1);
        return;
    }

    bool flag = false;
    for(int i = 0; i < n; ++i) {
        if(i == idx || eggs[i].first <= 0) continue;
        flag = true;
        
        eggs[idx].first -= eggs[i].second;
        eggs[i].first -= eggs[idx].second;
        hit(idx + 1);
        eggs[idx].first += eggs[i].second;
        eggs[i].first += eggs[idx].second;
    }

    if(!flag) hit(idx + 1);
}

int main() {
    FastIO;
    cin >> n;
    eggs.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> eggs[i].first >> eggs[i].second;
    }
    
    hit(0);
    cout << ans;
    
    return 0;
}
