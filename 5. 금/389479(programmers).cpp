#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int ans = 0;
    int now = 0;
    vector<int> release(24, 0);

    for (int i = 0; i < 24; i++) {
        now -= release[i];
        int need = players[i] / m;

        if (need > now) {
            int add = need - now;
            ans += add;
            now += add;
            if (i + k < 24) release[i + k] += add;
        }
    }
    return ans;
}