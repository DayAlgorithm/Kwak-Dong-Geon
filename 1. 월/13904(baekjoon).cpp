#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
vector<pair<int,int>> assignments;
bool done[1001];

int main() {
    FastIO;
    cin >> n;
    for(int i = 0; i < n; i++){
        int d, w;
        cin >> d >> w;
        assignments.push_back({w, d});
    }
    sort(assignments.rbegin(), assignments.rend());

    int ans = 0;
    for(auto &a : assignments){
        int w = a.first, d = a.second;
        for(int i = d; i > 0; i--){
            if(!done[i]){
                done[i] = true;
                ans += w;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
