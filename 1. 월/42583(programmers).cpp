#include <bits/stdc++.h>
using namespace std;


int solution(int b, int w, vector<int> t) {
    int ans = 0, wSum = 0;
    queue<int> q;
    for(int i = 0; i < b; ++i){
        q.push(0);
    }
    int i = 0;
    while(i < t.size()){
        int out = q.front();
        q.pop();
        wSum -= out;
        if(wSum + t[i] <= w){
            q.push(t[i]);
            wSum += t[i];
            i++;
        }
        else q.push(0);
        ans++;
    }
    while(!q.empty()){
        q.pop();
        ans++;
    }
    return ans;
}