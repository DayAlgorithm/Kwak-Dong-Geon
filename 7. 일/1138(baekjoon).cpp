#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, arr[11];
int main(){
    FastIO;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    vector<int> ans(n, 0);
    for(int i = 0; i < n; ++i){
        int cnt = arr[i];
        for(int j = 0; j < n; ++j){
            if(ans[j] == 0){
                if(cnt == 0){
                    ans[j] = i + 1;
                    break;
                }
                --cnt;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        cout << ans[i] << ' ';
    }    
    return 0;
}