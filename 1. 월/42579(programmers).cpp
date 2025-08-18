#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> ans;
    map<string, int> total;
    map<string, priority_queue<pair<int, int>>> infos;
    
    int n = genres.size();
    for(int i = 0; i < n; ++i){
        total[genres[i]] += plays[i];
        infos[genres[i]].push({plays[i], -i});
    }

    vector<pair<int, string>> order;
    for(auto &t : total) {
        order.push_back({t.second, t.first});
    }
    sort(order.rbegin(), order.rend());

    for(auto &o : order) {
        string genre = o.second;
        for(int i = 0; i < 2 && !infos[genre].empty(); ++i) {
            int top = infos[genre].top().second;
            infos[genre].pop();
            ans.push_back(-top);
        }
    }
    return ans;
}
