#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, k, cnt, ans;
vector<pair<int, bool>> belt;

int main(){
    FastIO;
    cin >> n >> k;
    int l = 2 * n, up = 0, down = n - 1;

    for(int i = 0; i < l; ++i){
        int a;
        cin >> a;
        belt.push_back({a, false});
    }

    while(cnt < k){
        ans++;
        up = (up - 1 + l) % l;
        down = (down - 1 + l) % l;
  
        if(belt[down].second) belt[down].second = false;
   
        for(int i = (down - 1 + l) % l; ; i = (i - 1 + l) % l){
            int next = (i + 1) % l;
            if(belt[i].second && !belt[next].second && belt[next].first){
                belt[i].second = false;
                belt[next].second = true;
                belt[next].first--;
                if(!belt[next].first) cnt++;
            }
            if(belt[down].second) belt[down].second = false;
            if(i == up) break;
        }

        if(belt[up].first && !belt[up].second){
            belt[up].second = true;
            belt[up].first--;
            if(!belt[up].first) cnt++;
        }
    }
    cout << ans;
    return 0;
}
