#include <bits/stdc++.h>

using namespace std;

priority_queue<int> frontQ;
priority_queue<int,vector<int>, greater<int>> backQ;
map<int, int> cnt;  //넣은 숫자 cnt

//명령에 따라 큐 조작
void carry(char order, int n){
    if(order == 'I'){   //넣는 명령 실행
        frontQ.push(n);
        backQ.push(n);
        cnt[n]++;
        return;
    }
    //최댓값 삭제
    if(n == 1 && !frontQ.empty()){
        cnt[frontQ.top()]--;
        frontQ.pop();
    }
    //최소값 삭제
    else if(n == -1 && !backQ.empty()){
        cnt[backQ.top()]--;
        backQ.pop();
    }
    //삭제후 각각 다른 큐에 남아있으면 안되는 숫자 삭제제
    while(!frontQ.empty() && !cnt[frontQ.top()]) frontQ.pop();
    while(!backQ.empty() && !cnt[backQ.top()]) backQ.pop();
    return;
}

vector<int> solution(vector<string> operations) {
    vector<int> ans;
    for(auto& o : operations){
        char order = o[0];
        int n = stoi(o.substr(2));  //숫자 부분 추출
        carry(order, n);
    }
    if(frontQ.empty() || backQ.empty()) ans = {0, 0};
    else ans = {frontQ.top(), backQ.top()};
    return ans;
}