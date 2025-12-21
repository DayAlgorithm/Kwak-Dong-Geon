#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
vector<pair<int,int>> lec;
bool visited[10001];

int main() {
    FastIO;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int p, d;
        cin >> p >> d;
        lec.push_back({p, d});
    }
    
    sort(lec.begin(), lec.end(), greater<pair<int,int>>());
    
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int p = lec[i].first;
        int d = lec[i].second;
        
        for(int j = d; j >= 1; --j){
            if(!visited[j]){
                visited[j] = true;
                ans += p;
                break;
            }
        }
    }
    
    cout << ans;
    return 0;
}
