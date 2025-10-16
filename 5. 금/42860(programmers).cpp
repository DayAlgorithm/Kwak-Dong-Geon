#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    int ans = 0, n = name.size();

    for(auto a : name){
        ans += min(a - 'A', 'Z' - a + 1);
    }

    int cnt = n - 1;
    for(int i = 0; i < n; ++i){
        int idx = i + 1;
        while(idx < n && name[idx] == 'A') idx++;
        
        int move1 = i * 2 + n - idx;
        int move2 = (n - idx) * 2 + i;
        cnt = min({cnt, move1, move2});
    }
    ans += cnt;
    return ans;
}