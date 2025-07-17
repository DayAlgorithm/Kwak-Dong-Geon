#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, hieght[50], cnt[50];

int main(){
    FastIO;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> hieght[i];
    }
    for(int i = 0; i < n; ++i){
        double maxDif = -INT_MAX;
        for(int j = i + 1; j < n; ++j){
            double dif = (double)(hieght[j] - hieght[i]) / (j - i);
            if(dif > maxDif){
                cnt[i]++;
                cnt[j]++;
                maxDif = dif;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans = max(ans, cnt[i]);
    }
    cout << ans;
    return 0;
}