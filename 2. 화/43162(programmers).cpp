#include <bits/stdc++.h>

using namespace std;

bool visited[201];

void bfs(int start, const vector<vector<int>>& computers){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int here = q.front();
        q.pop();
        for(int i = 0; i < computers[here].size(); ++i){
            if(computers[here][i] && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            bfs(i, computers);
            answer++;
        }
    }
    return answer;
}