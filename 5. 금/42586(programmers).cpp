#include <bits/stdc++.h>

using namespace std;

queue<int> q;   //완료까기 필요한 일수

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for(int i = 0; i < progresses.size(); ++i){
        int day = (100-progresses[i]) / speeds[i];
        if((100-progresses[i]) % speeds[i]) day++;
        q.push(day);
    }
    while(!q.empty()){
        int cnt = 1;
        int now = q.front();
        q.pop();
        while(!q.empty() && q.front() <= now){
            q.pop();
            cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}