#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, d, k, c, ans, used[3001];
vector<int> line;

int main() {
    FastIO;
    cin >> n >> d >> k >> c;
    for(int i = 0; i < n; ++i){
        int in;
        cin >> in;
        line.emplace_back(in);
    }

    int cnt = 0;
    for(int i = 0; i < k; ++i){
        if(!used[line[i]]) cnt++;
        used[line[i]]++;
    }
    ans = cnt;
    if(!used[c]) ans++;

    for(int left = 0; left < n; ++left){
        used[line[left]]--;
        if(!used[line[left]]) cnt--;
        int right = line[(left + k) % n];
        if(!used[right]) cnt++;
        used[right]++;

        int sum = cnt + (!used[c]);
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}
