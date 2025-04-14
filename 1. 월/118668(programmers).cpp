#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

const int INF = 987654321;

vector<vector<int>> problem;
int maxAlp, maxCop;

int cache[151][151];
int dp(int alp, int cop){
    //base case
    if(alp == maxAlp && cop == maxCop) return 0;
    
    //memorization
    int & ret = cache[alp][cop];
    if(ret != -1) return ret;
    
    ret = INF;
    for(int i = 0; i < problem.size(); ++i){
        //문제를 풀 수 없는 경우
        if(problem[i][0] > alp || problem[i][1] > cop) continue;
        
        int nAlp = alp + problem[i][2], nCop = cop + problem[i][3];
        if(nAlp > maxAlp) nAlp = maxAlp;
        if(nCop > maxCop) nCop = maxCop;
        ret = min(ret, dp(nAlp, nCop) + problem[i][4]);
    }
    return ret;
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    problem = problems;
    //푼제를 풀지앟고 1시간으로 alp, cop를 올리는 경우
    problem.push_back({0, 0, 1, 0, 1});
    problem.push_back({0, 0, 0, 1, 1});
    //필요한 alp, cop 최대 구하기기
    for(int i = 0; i < problems.size(); ++i){
        if(maxAlp < problem[i][0]) maxAlp = problem[i][0];
        if(maxCop < problem[i][1]) maxCop = problem[i][1];
    }
    memset(cache, -1, sizeof(cache));
    answer = dp(alp, cop);
    return answer;
}