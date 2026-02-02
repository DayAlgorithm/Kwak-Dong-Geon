#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n, l;
deque<pair<int, int>> nums;

int main(){
    FastIO;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        while (!nums.empty() && nums.back().first >= a) nums.pop_back();
        nums.emplace_back(a, i);
        if (nums.front().second <= i - l) nums.pop_front();
        cout << nums.front().first << ' ';
    }
    return 0;
}