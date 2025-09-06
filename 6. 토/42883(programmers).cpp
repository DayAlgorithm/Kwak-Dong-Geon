#include <bits/stdc++.h>
using namespace std;

deque<char> dq;
string solution(string number, int k) {
    string ans = "";
    
    for(auto num: number){
        while(!dq.empty() && k && dq.back() < num){
            dq.pop_back();
            k--;
        }
        dq.push_back(num);
    }
    
    while(k){
        dq.pop_back();
        k--;
    }
    
    while(!dq.empty()){
        ans += dq.front();
        dq.pop_front();
    }
    
    return ans;
}