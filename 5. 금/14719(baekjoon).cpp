#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int h, w, ans;
int height[501];

int main(){
    FastIO;
    cin >> h >> w;
    for(int i = 0; i < w; ++i){
        cin >> height[i];
    }
    for(int i = h; i > 0; --i){
        queue<int> q;
        for(int j = 0; j < w; ++j){
            if(height[j] >= i){
                q.push(j);
            }
        }
        int start, end;
        while(q.size() > 1){
            start = q.front();
            q.pop();
            end = q.front();
            ans += end - start - 1;
        }
    }
    cout << ans;
    return 0;
}