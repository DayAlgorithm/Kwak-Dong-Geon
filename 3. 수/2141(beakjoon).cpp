#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
long long sum, cnt;
vector<pair<int, int>> x;

int main(){
    FastIO;
    cin >> n;
    x.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i].first >> x[i].second;
        sum += x[i].second;
    }
    sort(x.begin(), x.end());
    for(auto a : x){
        cnt += a.second;
        if(cnt >= (sum + 1) / 2){
            cout << a.first;
            break;
        }
    }
    return 0;
}