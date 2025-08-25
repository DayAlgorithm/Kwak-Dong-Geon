#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int ans = 1;
    vector<string> type;
    map<string, int> typeCnt;
    for(auto c : clothes){
        if(!typeCnt[c[1]]){
            type.push_back(c[1]);
        }
        typeCnt[c[1]]++;
    }
    for(auto t : type){
        ans *= typeCnt[t] + 1;
    }
    ans--;
    return ans;
}