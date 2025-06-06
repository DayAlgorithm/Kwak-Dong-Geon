#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

long long n, m, k;
vector<pair<long long, long long>> cass;

bool is_possible(long long mid){
    long long sum = 0;
    int cnt = 0;
    for(int i = k - 1; i >= 0; --i){
        if(cnt == n) break;
        if(cass[i].second > mid) continue;
        else {
            sum += cass[i].first;
            cnt++;
        }
    }
    return (cnt == n && sum >= m);
}

int main(){
    FastIO;
    cin >> n >> m >> k;
    int M = 0;
    for(int i = 0; i < k; i++){
        long long a, b;
        cin >> a >> b;
        if(b > M) M = b;
        cass.push_back(make_pair(a, b));
    }
    sort(cass.begin(), cass.end());
    long long left = 1, right = M, ans = -1;
    while(left <= right){
        long long mid = (left + right) / 2;
        if(is_possible(mid)){
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    cout << ans;
    return 0;
}