#include<bits/stdc++.h>
using namespace std;

vector<string> ans;
vector<vector<string>> t;

bool dfs(string now, int cnt, vector<bool>& visited){
    ans.push_back(now);
    if(cnt == t.size()) return true;
    
    for(int i = 0; i < t.size(); ++i){
        if(t[i][0] != now || visited[i]) continue;
        string next = t[i][1];
        visited[i] = true;
        if(dfs(next, cnt + 1, visited)) return true;
        visited[i] = false;
        ans.pop_back();
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<bool> visited(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    t = tickets;
    dfs("ICN", 0, visited);
    return ans;
}