#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m;
bool used[41];

int fibo[41];
int dp() {
    fibo[0] = 1; fibo[1] = 1;

    for (int i = 2; i <= n; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    int ans = 1;
    int last = 0;
    for (int i = 1; i <= n; i++) {
        if (used[i]) {
            int len = i - last - 1;
            ans *= fibo[len];
            last = i;
        }
    }

    int len = n - last;
    ans *= fibo[len];

    return ans;
}

int main() {
    FastIO;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        used[x] = true;
    }

    cout << dp();
    return 0;
}
