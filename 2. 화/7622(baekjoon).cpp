#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int t, k, n;
char order;
priority_queue<int> frontQ;
priority_queue<int,vector<int>, greater<int>> backQ;
map<int, int> cnt;

void carry(){
    if(order == 'I'){
        frontQ.push(n);
        backQ.push(n);
        cnt[n]++;
        return;
    }
    if(n == 1 && !frontQ.empty()){
        cnt[frontQ.top()]--;
        frontQ.pop();
    }
    else if(n == -1 && !backQ.empty()){
        cnt[backQ.top()]--;
        backQ.pop();
    }
    while(!frontQ.empty() && !cnt[frontQ.top()]) frontQ.pop();
    while(!backQ.empty() && !cnt[backQ.top()]) backQ.pop();
    return;
}

int main() {
    FastIO;
    cin >> t;
    while(t--){
        cin >> k;
        cnt.clear();
        for(int i = 0; i < k; ++i){
            cin >> order >> n;
            carry();
        }
        if(frontQ.empty() || backQ.empty()) cout << "EMPTY\n";
        else cout << frontQ.top() << " " << backQ.top() << "\n";
        while(!frontQ.empty()) frontQ.pop();
        while(!backQ.empty()) backQ.pop();
    }
    return 0;
}