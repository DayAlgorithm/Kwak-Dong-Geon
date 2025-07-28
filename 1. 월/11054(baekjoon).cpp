#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n, ans = 1;
int arr[1001], dp_left[1001], dp_right[1001];

int main(){
    FastIO
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }
    for(int i = 1; i <= n; ++i){
        dp_left[i] = 1;
        for(int j = 0; j < i; ++j){
            if(arr[j] < arr[i] &&  dp_left[j] + 1 > dp_left[i]){
                dp_left[i] = dp_left[j] + 1;
            }
        }
    }
    for(int i = n; i >= 1; --i){
        dp_right[i] = 1;
        for(int j = n; j > i; --j){
            if(arr[j] < arr[i] &&  dp_right[j] + 1 > dp_right[i]){
                dp_right[i] = dp_right[j] + 1;
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        ans = max(ans, dp_left[i] + dp_right[i] - 1);
    }
    cout << ans;
    return 0;
}