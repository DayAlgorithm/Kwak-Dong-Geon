#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, nums[101];
vector<int> ans;

bool visited[101];
void dfs(int idx, int num){
    if(visited[idx]){
        if(idx == num) ans.push_back(idx);
        return;
    }
    visited[idx] = true;
    dfs(nums[idx], num);
}

int main(){
    FastIO;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> nums[i];
    }
    for(int i = 1; i <= n; ++i){
        memset(visited, false, sizeof(visited));
        dfs(i, i);
    }
    cout << ans.size() << "\n";
    for(auto a : ans) cout << a << "\n";
    return 0;
}