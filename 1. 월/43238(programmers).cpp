#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    long long ans;
    long long left = 1, right = 0;
    for(auto& t : times) if(right < t) right = t;
    right *= n; //최대 검사시간 저장
    ans = right;
    
    long long cnt, mid;
    //이분탐색
    while(left <= right){
        cnt = 0;
        mid = (left + right) / 2;
        for(auto& t : times) cnt += mid / t;    //현재 시간에서 검사 할 수 있는 사람의 수
        if(cnt < n) left = mid + 1;
        else{
            right = mid - 1;
            ans = mid;
        }
    }
    return ans;
}