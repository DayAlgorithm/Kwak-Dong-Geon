#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m;
vector<int> pos, neg;

int main() {
    FastIO;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        if(x > 0) pos.push_back(x);
        else neg.push_back(x);
    }
    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end());
    
    int ans = 0;
    vector<int> dist;
    
    for(int i = 0; i < pos.size(); i += m){
        dist.push_back(pos[i]);
    }
    for(int i = 0; i < neg.size(); i += m){
        dist.push_back(abs(neg[i]));
    }
    
    sort(dist.begin(), dist.end(), greater<int>());
    
    ans += dist[0];
    for(int i = 1; i < dist.size(); ++i){
        ans += dist[i] * 2;
    }
    
    cout << ans;
    return 0;
}
