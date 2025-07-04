#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, k, ans;
int adj[10][10];
vector<int> j;
int g[21], m[21];

int main() {
    FastIO;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> adj[i][j];
        }
    }

    j.resize(n + 1);
    for(int i = 1; i <= n; ++i) j[i] = i;
    for(int i = 1; i <= 20; ++i) cin >> g[i];
    for(int i = 1; i <= 20; ++i) cin >> m[i];

    while(true) {
        int idx[4] = {0, 1, 1, 1};
        int cnt[4] = {0, 0, 0, 0};
        int win = -1;
        int now = 1, nxt = 2;
        deque<int> dq = {3};

        while(true) {
            int move_cur, move_nxt;
            if(now == 1) move_cur = j[idx[1]++];
            else if(now == 2) move_cur = g[idx[2]++];
            else move_cur = m[idx[3]++];

            if(nxt == 1) move_nxt = j[idx[1]++];
            else if(nxt == 2) move_nxt = g[idx[2]++];
            else move_nxt = m[idx[3]++];

            int res = adj[move_cur][move_nxt];
            if(res == 0 || (res == 1 && now < nxt)){
                cnt[nxt]++;
                dq.push_back(now);
                now = nxt;
                nxt = dq.front();
                dq.pop_front();
            } 
            else{
                cnt[now]++;
                dq.push_back(nxt);
                nxt = dq.front();
                dq.pop_front();
            }

            int max_idx = 1;
            for(int i = 2; i <= 3; ++i){
                if(cnt[i] > cnt[max_idx]) max_idx = i;
            }

            if(cnt[max_idx] == k) {
                win = max_idx;
                break;
            }
            if(idx[1] > n) break;
        }

        if(win == 1){
            ans = 1;
            break;
        }
        if(!next_permutation(j.begin() + 1, j.end())) break;
    }

    cout << ans << '\n';
    return 0;
}
