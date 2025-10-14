#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> ans;
    int h, w;
    for(int i = 0; i < park.size(); ++i){
        int j;
        for(j = 0; j < park[i].size(); ++j){
            if(park[i][j] == 'S'){
                h = i;
                w = j;
                break;
            }
        }
        if(j != park[i].size()) break;
    }

    for(auto r: routes){
        char dir = r[0];
        int n = r[2] - '0';

        int nh = h, nw = w;
        bool flag = true;
        for(int i = 1; i <= n; ++i){
            if(dir == 'N'){
                nh = h - i;
                nw = w;
            } else if(dir == 'S'){
                nh = h + i;
                nw = w;
            } else if(dir == 'W'){
                nh = h;
                nw = w - i;
            } else if(dir == 'E'){
                nh = h;
                nw = w + i;
            }
            if(nh < 0 || nw < 0 || nh >= park.size() || nw >= park[0].size() || park[nh][nw] == 'X'){
                flag = false;
                break;
            }
        }
        if(flag){
            if(dir == 'N') h -= n;
            else if(dir == 'S') h += n;
            else if(dir == 'W') w -= n;
            else if(dir == 'E') w += n;
        }
    }
    ans.push_back(h);
    ans.push_back(w);
    return ans;
}
