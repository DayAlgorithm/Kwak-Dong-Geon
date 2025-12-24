#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m, start = 100;
int broken[10];

bool canPress(int num) {
    if(num == 0) return !broken[0];
    while(num > 0) {
        if(broken[num % 10]) return false;
        num /= 10;
    }
    return true;
}

int countDigit(int num) {
    if(num == 0) return 1;
    int cnt = 0;
    while(num > 0) {
        cnt++;
        num /= 10;
    }
    return cnt;
}

int main() {
    FastIO;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        broken[x] = 1;
    }
    
    int ans = abs(n - start);

    for(int i = 0; i <= 1000000; i++) {
        if(canPress(i)) {
            int press = countDigit(i) + abs(n - i);
            ans = min(ans, press);
        }
    }
    
    cout << ans;
    
    return 0;
}
