#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, h, ans;

int main() {
    FastIO;
    cin >> n;
    
    vector<pair<int,int>> v(n);
    int maxH = 0, maxIdx = 0;
    
    for(int i = 0; i < n; ++i){
        cin >> v[i].first >> v[i].second;
        if(v[i].second > maxH){
            maxH = v[i].second;
            maxIdx = i;
        }
    }
    
    sort(v.begin(), v.end());
    for(int i = 0; i < n; ++i){
        if(v[i].second == maxH){
            maxIdx = i;
            break;
        }
    }
    
    h = 0;
    for(int i = 0; i <= maxIdx; ++i){
        if(v[i].second > h){
            h = v[i].second;
        }
        if(i < maxIdx){
            ans += h * (v[i+1].first - v[i].first);
        }
    }

    h = 0;
    for(int i = n-1; i >= maxIdx; --i){
        if(v[i].second > h){
            h = v[i].second;
        }
        if(i > maxIdx){
            ans += h * (v[i].first - v[i-1].first);
        }
    }
    
    ans += maxH;
    cout << ans;
    
    return 0;
}
