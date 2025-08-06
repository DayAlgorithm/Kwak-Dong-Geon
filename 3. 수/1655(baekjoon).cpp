#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
priority_queue<int> L;
priority_queue<int, vector<int>, greater<int>> R;

int main() {
    FastIO;
    cin >> n;
    int num;

    for(int i = 1; i <= n; ++i){
        cin >> num;
        if(L.empty() || num <= L.top()) L.push(num);
        else R.push(num);

        if(L.size() > R.size() + 1){
            R.push(L.top());
            L.pop();
        }
        if(R.size() > L.size()){
            L.push(R.top());
            R.pop();
        }

        cout << L.top() << "\n";
    }
    return 0;
}
