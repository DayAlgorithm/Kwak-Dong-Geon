#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
vector<pair<int, int>> lec;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    FastIO;    
    cin >> n;

    for(int i = 0; i < n; i++){
        int id, s, e;
        cin >> id >> s >> e;
        lec.push_back({s, e});
    }

    sort(lec.begin(), lec.end());

    for(int i = 0; i < n; i++){
        if(!pq.empty() && pq.top() <= lec[i].first){
            pq.pop();
        }
        pq.push(lec[i].second);
    }

    cout << pq.size();
    
    return 0;
}