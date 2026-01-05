#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
vector<int> sequence;

int main() {
    FastIO;
    cin >> n;
    sequence.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    
    if(prev_permutation(sequence.begin(), sequence.end())) {
        for(auto &i : sequence) {
            cout << i << " ";
        }
    } else {
        cout << "-1";
    }
    
    return 0;
}
