#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m, k, ans;
vector<string> lamp;

int main(){
    FastIO;
    cin >> n >> m;
    lamp.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> lamp[i];
    }
    cin >> k;
    for(auto line : lamp){
        int cnt = 0, sum = 0;
        for(auto c : line){
            if(c == '0') cnt++;
        }
        if(cnt <= k && cnt % 2 == k % 2){
            for(auto l : lamp){
                if(line == l) sum++;
            }
        }
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}