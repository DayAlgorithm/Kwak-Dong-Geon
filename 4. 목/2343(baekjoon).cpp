#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m;
int length[1000001];

bool is_possible(int mid){
    long long sum = 0;
    int cnt = 0;
    for(auto i : length){
        if(i > mid) return 0;
        sum += i;
        if(sum > mid){
            sum = i;
            cnt++;
        }
        else if(sum == mid){
            sum = 0;
            cnt++;
        }
    }
    if(sum == 0) return (cnt <= m);
    else return (cnt + 1 <= m);
}

int main(){
    FastIO;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> length[i];
    }
    long long left = 1, right = 1e9 + 2, ret = 0;
    while(left <= right){
        long long mid = (left + right) / 2;
        if(is_possible(mid)){
            ret = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }
    cout << ret;
    return 0;
}