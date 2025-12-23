#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int d;
string s;
long long x, y;

int main() {
    FastIO;
    cin >> d >> s;
    cin >> x >> y;
    y = -y;
    
    long long cx = 0, cy = 0;
    long long sz = 1LL << d;
    
    for(int i = 0; i < d; i++) {
        cx <<= 1;
        cy <<= 1;
        int num = s[i] - '0';
        
        if(num == 1 || num == 4) cx++;
        if(num == 3 || num == 4) cy++;
    }
    cx += x;
    cy += y;
    
    if(cx < 0 || cx >= sz || cy < 0 || cy >= sz) {
        cout << -1;
        return 0;
    }
    
    string ans = "";
    for(int i = d - 1; i >= 0; i--) {
        bool rx = cx & (1LL << i);
        bool ry = cy & (1LL << i);

        if(rx && ry) ans += '4';
        else if(rx && !ry) ans += '1';
        else if(!rx && ry) ans += '3';
        else ans += '2';
    }
    
    cout << ans;
    return 0;
}
