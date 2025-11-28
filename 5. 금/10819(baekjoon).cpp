#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
int num[9];
int ans = 0;

int main() {
    FastIO;    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    sort(num, num + n);
    int sum = 0;
    for(int i = 0; i < n - 1; i++){
        sum += abs(num[i] - num[i+1]);
    }    
    if(sum > ans) ans = sum;
    
    while(next_permutation(num, num + n)){
        sum = 0;
        for(int i = 0; i < n - 1; i++) {
            sum += abs(num[i] - num[i+1]);
        }
        if(sum > ans) ans = sum;
    }
    
    cout << ans;

    return 0;
}