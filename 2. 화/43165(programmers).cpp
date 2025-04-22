#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;

int bfs(const vector<int>& numbers, int target){
    int cntPath = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()){
        int here = q.front().first, idx = q.front().second;
        q.pop();
        if(idx == numbers.size()){  //마지막 숫자까지 탐색한 경우
            if(here == target) cntPath++;   //타겟 넘버가 만들어졌을때 cnt
            continue;
        }
        int edge = numbers[idx];
        int there1 = here + edge, there2 = here - edge;
        q.push({there1, idx + 1});
        q.push({there2, idx + 1});
    }
    return cntPath;
}

int solution(vector<int> numbers, int target) {
    return bfs(numbers, target);
}