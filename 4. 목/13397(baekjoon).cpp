#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m;
vector<int> nums;

bool canDivide(int maxScore) {
    int cnt = 1;
    int s = nums[0], S = nums[0];
    
    for(int i = 1; i < n; ++i) {
        s = min(s, nums[i]);
        S = max(S, nums[i]);
        
        if(S - s > maxScore) {
            cnt++;
            s = nums[i];
            S = nums[i];
        }
    }
    
    return cnt <= m;
}

int main() {
    FastIO;
    cin >> n >> m;
    nums.resize(n);
    
    int left = 0, right = 0;
    
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
        right = max(right, nums[i]);
    }
    
    int ans = right;
    
    while(left <= right){
        int mid = (left + right) / 2;
        
        if(canDivide(mid)) {
            ans = mid;
            right = mid - 1;
        } 
        else left = mid + 1;
    }
    
    cout << ans;
    
    return 0;
}
