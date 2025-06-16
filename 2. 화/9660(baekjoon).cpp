#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long n;

int main(){
    FastIO;
    cin >> n;
    if(!(n % 7) || n % 7 == 2) cout << "CK";
    else cout << "SK";
    return 0;
}