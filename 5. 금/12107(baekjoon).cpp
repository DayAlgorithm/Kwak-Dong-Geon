#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
int main(){
    FastIO;
    cin >> n;
    if(n % 2) cout << 'B';
    else cout << 'A';
    return 0;
}