#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> lines){
    vector<pair<int,int>> sec;
    for(auto& line : lines){
        int hour = stoi(line.substr(11,2));
        int min = stoi(line.substr(14,2));
        int second = stoi(line.substr(17,2));
        int millisec = stoi(line.substr(20,3));

        int end_time = (hour * 3600 + min * 60 + second) * 1000 + millisec;

        double task_time = stod(line.substr(24, line.size() - 25));
        int task_ms = (int)(task_time * 1000);

        int start_time = end_time - task_ms + 1;

        sec.emplace_back(start_time, end_time);
    }

    int ans = 0;
    for(auto &s : sec){
        int start = s.second, end = start + 999, cnt = 0;
        for(auto &in : sec){
            if(in.first <= end && in.second >= start){
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    return ans;
}
