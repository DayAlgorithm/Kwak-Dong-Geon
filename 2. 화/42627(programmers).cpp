#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> jobs){
    int ans = 0;
    int time = 0, total = jobs.size();
    sort(jobs.begin(), jobs.end(), cmp);
    while(!jobs.empty()){
        for(int i = 0; i < jobs.size(); ++i){
            if(jobs[i][0] <= time){
                time += jobs[i][1];
                ans += time - jobs[i][0];
                jobs.erase(jobs.begin() + i);
                break;
            }
            if(i == jobs.size() - 1) time++;
        }
    }
    return ans / total;
}