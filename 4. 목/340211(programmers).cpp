#include <bits/stdc++.h>

using namespace std;

map<pair<int, pair<int, int>>, int> checkCrash;
int ans = 0;

void move(const vector<vector<int>>& point, const vector<int>& path){
    pair<int, int> start = {point[path[0] - 1][0], point[path[0] - 1][1]};

    //충돌 검사
    if(checkCrash[{0, start}] == 1) ans++;
    checkCrash[{0, start}]++;   //시작 지점에 로봇 체크크
    
    int t = 1;
    for(int i = 1; i < path.size(); ++i){
        pair<int, int> end = {point[path[i] - 1][0], point[path[i] - 1][1]};
        while(start != end){    //목표에 도달할때 까지
            if(start.first != end.first){  //y좌표 부터 이동
                if(start.first > end.first) start.first--;
                else start.first++;
            }
            else if(start.second != end.second){
                if(start.second > end.second) start.second--;
                else start.second++;
            }
            
            if(checkCrash[{t, start}] == 1) ans++;  //충돌 검사
            checkCrash[{t, start}]++;   //t시잔에 start 지점에 있는 로봇 체크
            t++;
        }
    }
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    for(auto& path : routes){   //각 로봇을 경로에 따라 이동
        move(points, path);
    }
    return ans;
}