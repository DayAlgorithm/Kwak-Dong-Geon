#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int g, cnt;

int main(){
    FastIO;
    cin >> g;
    long long left = 1, right = 2, dif;
    while(left < right){
        dif = right * right - left * left;
        if(dif == g){
            cout << right << "\n";
            cnt++;
            right++;
        }
        else if(dif > g) left++;
        else right++;
    }
    if(!cnt) cout << -1 << "\n";
    return 0;
}