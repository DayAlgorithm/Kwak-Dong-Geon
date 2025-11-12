#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
int maxCache[2][3], minCache[2][3];

int main() {
    FastIO;
    cin >> n;
    int k = 0;
    int a, b, c;
    for(int i = 0; i < n; ++i){
        cin >> a >> b >> c;

        maxCache[k][0] = max(maxCache[1 - k][0], maxCache[1 - k][1]) + a;
        maxCache[k][1] = max(max(maxCache[1 - k][0], maxCache[1 - k][1]), maxCache[1 - k][2]) + b;
        maxCache[k][2] = max(maxCache[1 - k][1], maxCache[1 - k][2]) + c;

        minCache[k][0] = min(minCache[1 - k][0], minCache[1 - k][1]) + a;
        minCache[k][1] = min(min(minCache[1 - k][0], minCache[1 - k][1]), minCache[1 - k][2]) + b;
        minCache[k][2] = min(minCache[1 - k][1], minCache[1 - k][2]) + c;

        k = 1 - k;
    }

    int M, m;
    M = max(max(maxCache[1- k][0], maxCache[1 - k][1]), maxCache[1 - k][2]);
    m = min(min(minCache[1 - k][0], minCache[1 - k][1]), minCache[1 - k][2]);
    cout << M << " " << m << "\n";
    
    return 0;
}
