#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m , l, k;
vector<pair<int, int>> point;

int main(){
    FastIO;
    cin >> n >> m >> l >> k;
    point = vector<pair<int, int>>(k);
    for(int i = 0; i < k; ++i){
        cin >> point[i].first >> point[i].second;
    }
    int ans = 0, cnt = 0;
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < k; ++j){
            int y = point[i].first, x = point[j].second;
            int cnt = 0;
            for(auto p : point){
                int ny = p.first, nx = p.second;
                if(ny >= y && ny <= y + l && nx >= x && nx <= x + l) cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    cout << k - ans << "\n";
    return 0;
}