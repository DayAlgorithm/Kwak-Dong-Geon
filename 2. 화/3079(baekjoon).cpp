#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m;
long long t[1000001], ans = LONG_MAX;

int main(){
    FastIO;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> t[i];
    }
    sort(t, t + n);
    long long left = 1, right = m * t[0], mid, cnt;
    while(left <= right){
        mid = (left + right) / 2;
        cnt = 0;
        for(int i = 0; i < n; ++i){
            cnt += mid / t[i];
        }
        if(cnt >= m){
            if(ans > mid) ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    cout << ans;
    return 0;
}
