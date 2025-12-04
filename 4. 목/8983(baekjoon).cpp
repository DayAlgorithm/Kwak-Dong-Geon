#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int m, n;
long long l, pos[100001];
vector<pair<long long, long long>> animals;

int main() {
    FastIO;
    cin >> m >> n >> l;
    for(int i = 0; i < m; i++){
        cin >> pos[i];
    }
    animals.resize(n);
    for(int i = 0; i < n; i++){
        cin >> animals[i].first >> animals[i].second;
    }

    sort(pos, pos + m);

    int cnt = 0;
    for(int i = 0; i < n; i++){
        long long x = animals[i].first, y = animals[i].second;

        if(y > l) continue;

        int idx = lower_bound(pos, pos + m, x) - pos;
        if(idx < m){
            if(abs(pos[idx] - x) + y <= l){
                cnt++;
                continue;
            }
        }
        if(idx > 0){
            if(abs(pos[idx - 1] - x) + y <= l) cnt++;
        }
    }

    cout << cnt;
    
    return 0;
}