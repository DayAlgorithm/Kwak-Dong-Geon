#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n, c;
int home[200001] = {0,};

bool is_possible(int mid){
    long long sum = 0;
    int cnt = 1;
    for(int i = 1; i < n; ++i){
        sum += home[i] - home[i - 1];
        if(sum >= mid){
            sum = 0;
            cnt++;
        }
    }
    return (cnt >= c);
}

int main(){
    FastIO;
    cin >> n >> c;
    for(int i = 0; i < n; ++i){
        cin >> home[i];
    }
    sort(home, home + n);
    long long left = 1, right = 1e9, ret = 0;
    while(left <= right){
        long long mid = (left + right) / 2;
        if(is_possible(mid)){
            ret = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << ret;
    return 0;
}
