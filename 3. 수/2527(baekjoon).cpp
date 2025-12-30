#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;


int x1, yy1, p1, q1;
int x2, yy2, p2, q2;


char checkOverlap() {
    if(x1 > p2 || x2 > p1 || yy1 > q2 || yy2 > q1) return 'd';
    else if((x1 == p2 && (yy1 == q2 || yy2 == q1)) ||
             (p1 == x2 && (yy1 == q2 || yy2 == q1))) {
        return 'c';
    } 
    else if(x1 == p2 || x2 == p1 || yy1 == q2 || yy2 == q1) return 'b';
    return 'a';
}


int main() {
    FastIO;
    for(int i = 0; i < 4; ++i) {
        cin >> x1 >> yy1 >> p1 >> q1 >> x2 >> yy2 >> p2 >> q2;
        cout << checkOverlap() << '\n';
    }
    return 0;
}
