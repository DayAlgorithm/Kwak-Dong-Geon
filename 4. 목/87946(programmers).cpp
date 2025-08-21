#include <bits/stdc++.h>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int ans = 0;
    int n = dungeons.size();
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);

    do {
        int now = k;
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            int idx = ord[i];
            int need = dungeons[idx][0], cost = dungeons[idx][1];
            if(now >= need) {
                now -= cost;
                cnt++;
            }
        }
        ans = max(ans, cnt);
    } while(next_permutation(ord.begin(), ord.end()));

    return ans;
}
