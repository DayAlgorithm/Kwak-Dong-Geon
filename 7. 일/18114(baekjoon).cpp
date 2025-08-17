#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
long long c, w[5001];

int main(){
    FastIO;
    cin >> n >> c;
    for(int i = 0; i < n; ++i){
        cin >> w[i];
    }
    sort(w, w + n);

    if(binary_search(w, w + n, c)){
        cout << 1;
        return 0;
    }
    for(int i = 0; i < n; ++i){
        long long target = c - w[i];
        if(target <= 0) continue;
        if(binary_search(w + i + 1, w + n, target)){
            cout << 1;
            return 0;
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            long long target = c - w[i] - w[j];
            if(target <= 0) continue;
            auto it = lower_bound(w, w + n, target);
            if(it != w + n && *it == target){
                int idx = it - w;
                if(idx != i && idx != j){
                    cout << 1;
                    return 0;
                }
            }
        }
    }

    cout << 0;
    return 0;
}
