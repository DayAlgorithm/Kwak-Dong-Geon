#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int INF = 987654321;

int n, h;
int t[500001], b[500001];
pair<int, int> ans = {INF, 0};

int main() {
    FastIO;
    cin >> n >> h;
    int num;
    for(int i = 0; i < n; ++i){
        cin >> num;
        if(i % 2) t[h - num + 1]++;
        else b[num]++;
    }
    for(int i = 1; i <= h; ++i){
        t[i] += t[i - 1];
        b[h - i] += b[h - i + 1];
    }
    for(int i = 1; i <= h; ++i){
        int sum = t[i] + b[i];
        if(ans.first > sum){
            ans.first = sum;
            ans.second = 1;
        } else if(ans.first == sum) ans.second++;
    }
    cout << ans.first << " " << ans.second;
    return 0;
}