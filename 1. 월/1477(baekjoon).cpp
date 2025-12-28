#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m, l;
int d[51];

bool is_possible(int mid) {
    long long cnt = 0;
    long long M = 0;

    for(int i = 1; i <= n + 1; i++) {
        if(d[i] - d[i - 1] > mid) {
            if((d[i] - d[i - 1]) % mid == 0) {
                cnt += (d[i] - d[i - 1]) / mid - 1;    
            }
            else cnt += (d[i] - d[i - 1]) / mid;
        }
    }
    return (cnt <= m);
}

int main() {
    FastIO;
    cin >> n >> m >> l;
    d[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    d[n + 1] = l;
    sort(d, d + n + 1);

    long long left = 1, right = l, ret = 0;
    while(left <= right) {
        long long mid = (left + right) / 2;
        if(is_possible(mid)) {
            ret = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    cout << ret;
    return 0;
}
