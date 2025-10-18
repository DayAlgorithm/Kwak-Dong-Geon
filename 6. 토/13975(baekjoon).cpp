#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int t;
int main(){
    FastIO;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> fileSizes;
        for(int i = 0; i < n; ++i){
            int size;
            cin >> size;
            fileSizes.push(size);
        }
        long long ans = 0;
        while(fileSizes.size() > 1){
            int first = fileSizes.top(); fileSizes.pop();
            int second = fileSizes.top(); fileSizes.pop();
            int mergedSize = first + second;
            ans += mergedSize;
            fileSizes.push(mergedSize);
        }
        cout << ans << '\n';
    }
    return 0;
}