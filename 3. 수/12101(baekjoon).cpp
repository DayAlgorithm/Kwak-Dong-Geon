#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n, k, cnt;

void makeN(vector<int>& path, int sum){
    if(sum > n) return;
    if(sum == n){
        ++cnt;
        if(cnt == k){
            for(int i = 0; i < path.size() - 1; ++i){
                cout << path[i] << "+";
            }
            cout << path[path.size() - 1];
        }
    }
    
    for(int i = 1; i <= 3; ++i){
        path.push_back(i);
        makeN(path, sum + i);
        path.pop_back();
    }
}

int main(){
    FastIO;
    cin >> n >> k;
    vector<int> ans;
    makeN(ans, 0);
    if(cnt < k) cout << -1;
    return 0;
}