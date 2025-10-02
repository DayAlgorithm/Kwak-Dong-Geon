#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, s;
vector<int> nums;

void solve() {
    for(int i = 0; i < n && s > 0; ++i){
        int pos = i;
        for(int j = i + 1; j < n && j <= i + s; ++j){
            if(nums[j] > nums[pos]) pos = j;
        }
        for(int j = pos; j > i; --j){
            swap(nums[j], nums[j - 1]);
        }
        s -= (pos - i);
    }
}

int main() {
    FastIO;
    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cin >> s;
    solve();
    for (auto &num : nums) {
        cout << num << " ";
    }
    return 0;
}
