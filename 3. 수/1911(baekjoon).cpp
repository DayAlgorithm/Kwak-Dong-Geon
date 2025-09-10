#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, l;
int main(){
    FastIO;
    cin >> n >> l;
    int start, end, e = 0, cnt = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 0; i < n; ++i){
        cin >> start >> end;
        pq.push({start, end});
    }
    while(!pq.empty()){
        start = pq.top().first, end = pq.top().second;
        pq.pop();
        while(e < end){
            if(e < start) e = start + l;
            else e = e + l;
            cout << e << " ";
            cnt++;
        }
    }
    cout << "\n";
    cout << cnt;
    return 0;
}