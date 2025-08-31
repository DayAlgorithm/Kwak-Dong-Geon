#include <bits/stdc++.h>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int ans = 0, left = 0, right = distance;
    sort(rocks.begin(), rocks.end());
 
    while(left <= right){
        int mid = (left + right) / 2;
        int pre = 0, cnt = 0;
 
        for(int i = 0; i < rocks.size(); ++i){
            if(rocks[i] - pre < mid) cnt++;
            else pre = rocks[i];
        }
        if(distance - pre < mid) cnt++;
 
        if(cnt <= n){
            ans = max(mid, ans);
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return ans;
}