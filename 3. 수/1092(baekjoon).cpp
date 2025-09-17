#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int main() {
    FastIO;
    int n, m;
    cin >> n;
    vector<int> cranes(n);
    for(int i = 0; i < n; ++i) cin >> cranes[i];
    cin >> m;
    vector<int> boxes(m);
    for(int i = 0; i < m; ++i) cin >> boxes[i];

    sort(cranes.rbegin(), cranes.rend());
    sort(boxes.rbegin(), boxes.rend());

    if(boxes[0] > cranes[0]){
        cout << -1;
        return 0;
    }

    vector<int> pos(n, 0);
    vector<bool> checked(m, false);
    int moved = 0, ans = 0;
    while(moved < m){
        for(int i = 0; i < n; ++i){
            while(pos[i] < m){
                if(!checked[pos[i]] && cranes[i] >= boxes[pos[i]]){
                    checked[pos[i]] = true;
                    ++pos[i]; ++moved;
                    break;
                }
                ++pos[i];
            }
        }
        ++ans;
    }
    cout << ans;
    return 0;
}
