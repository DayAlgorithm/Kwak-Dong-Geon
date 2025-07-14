#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, l, p, gas[1000001];

priority_queue<int> pq;
int cntStop(){
    int cnt = 0;
    for(int i = 1; i < l; ++i){
        --p;
        if(gas[i]) pq.push(gas[i]);
        if(!p){
            if(pq.empty()) return -1;
            p += pq.top();
            pq.pop();
            cnt++;
        }
    }
    return cnt;
}

int main(){
    FastIO;
    cin >> n; 
    int a, b;
    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        gas[a] = b;
    }
    cin >> l >> p;
    cout << cntStop();
    return 0;
}