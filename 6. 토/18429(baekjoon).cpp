#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n, k, weight[8];

int cnt(int day, int remain){
    if(!day) return 1;
    int ret = 0;
    for(int i = 0; i < n; ++i){
        //사용하지 않은 키트 중에 500이상을 유지 할 수 있는 키트
        if(weight[i] && weight[i] + remain >= k){
            int temp = weight[i];
            weight[i] = 0;
            ret += cnt(day - 1, remain - k + temp);
            weight[i] = temp;   //복원
        }
    }
    return ret;
}

int main(){
    FastIO;
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> weight[i];
    }
    cout << cnt(n, 0);
    return 0;
}