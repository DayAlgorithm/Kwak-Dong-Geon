#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> ans(size);
    stack<int> s;
    for(int i = 0; i < size; ++i){
        while(!s.empty() && prices[s.top()] > prices[i]){
            ans[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        ans[s.top()] = size - s.top() - 1;
        s.pop();
    }
    return ans;
}