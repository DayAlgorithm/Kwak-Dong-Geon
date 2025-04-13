#include <bits/stdc++.h>
using namespace std;

priority_queue<long long> pq;

int cntMix(int K){
    int ret = 0;
    while(pq.size() > 1){
        if(-pq.top() >= K) return ret; //가장 작은 스코필 지수가 K 이상일때
        long long min = -pq.top(); pq.pop();    //가장 맵지 않은 음식
        long long min2 = -pq.top(); pq.pop();   //두 번째로 맵지 않은 음식
        pq.push(-(min + min2 * 2)); //스코필 지수 올리기
        ret++;  //섞은 횟수 카운트
    }
    if(-pq.top() >= K) return ret;  //가장 작은 스코필 지수가 K 이상일때
    return -1;  //K 이상으로 만드는게 불가능 할때
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(int i = 0; i < scoville.size(); ++i){
        pq.push(-scoville[i]);  //오름차순 정렬
    }
    answer = cntMix(K);
    return answer;
}