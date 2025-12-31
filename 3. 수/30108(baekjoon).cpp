#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
vector<int> a;

int main() {
    FastIO;
    cin >> n;
    a.resize(n + 1, 0);
    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin() + 1, a.end(), greater<int>());
    
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += a[i];
        cout << ans << '\n';
    }
    
    return 0;
}
