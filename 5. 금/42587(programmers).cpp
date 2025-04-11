#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> q;    //process 저장
priority_queue<int> pq;     //process 우선순위 저장

//process 실행
int process(int location){
    int ret = 1;    //실행한 process 개수 저장
    while(true){
        pair<int, int> temp = q.front();
        q.pop();
        if(temp.first < pq.top()){  //process 중에 우선순위가 더 높은게 존재하는 경우
            q.push(temp);   //queue 뒤에 다시 넣는다
            continue;   //process를 실행하지 않고 건너뛰기
        }
        //process를 실행하는 경우
        pq.pop();
        if(temp.second == location){    //실행항 process가 타겟인 경우우
            return ret;
        }
        ret++;
    }
    return -1;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    for(int i = 0; i < priorities.size(); ++i){ 
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    answer = process(location);
    return answer;
}