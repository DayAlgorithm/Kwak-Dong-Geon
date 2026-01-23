#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int r, c, ans;
vector<string> a;
vector<string> b;

int main(){
    FastIO;
    cin >> r >> c;
    a.resize(r); b.resize(r);
    for (int i = 0; i < r; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < r; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (b[i][j] != a[i][j]) {
                if (j + 3 > c || i + 3 > r) {
                    cout << -1;
                    return 0;
                }
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        if (a[k][l] - '0') a[k][l] = '0';
                        else a[k][l] = '1';
                    }
                }
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}