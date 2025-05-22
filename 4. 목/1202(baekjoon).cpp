#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n, k, cnt;
long long ans;
vector<pair<int, int>> jewel;
multiset<int> bag;

int main(){
    FastIO;
    cin >> n >> k;
    int w, v;
    for(int i = 0; i < n; ++i){
        cin >> w >> v;
        jewel.push_back({v, w});
    }
    sort(jewel.begin(), jewel.end());
    for(int i = 0; i < k; ++i){
        cin >> w;
        bag.insert(w);
    }
    for(int i = n - 1; i >= 0; i--){
        auto iter = bag.lower_bound(jewel[i].second);
        if(iter == bag.end()) continue;
        bag.erase(iter);
        cnt++;
        ans += jewel[i].first;
        if(cnt == k) break;
    }
    cout << ans;
    return 0;
}