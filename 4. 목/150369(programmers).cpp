#include <bits/stdc++.h>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int deliver = 0, pickup = 0;
    for(int i = n - 1; i >= 0; --i){
        deliver += deliveries[i];
        pickup += pickups[i];
        int cnt = 0;
        while(deliver > 0 || pickup > 0){
            deliver -= cap;
            pickup -= cap;
            cnt++;
        }
        answer += (i + 1) * cnt * 2;
    }
    return answer;
}