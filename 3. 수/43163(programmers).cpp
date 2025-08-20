#include <bits/stdc++.h>
using namespace std;

bool cntDif(string a, string b) {
    int cnt = 0, size = a.size();
    for(int i = 0; i < size; ++i) {
        if(a[i] != b[i]) cnt++;
        if(cnt > 1) return false;
    }
    return cnt == 1;
}

int bfs(string begin, string target, vector<string>& words) {
    int size = words.size();
    vector<int> visited(size + 1, 0);
    queue<pair<string, int>> q;

    q.push({begin, 0});

    while(!q.empty()) {
        string here = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(here == target) return cnt;
        for(int i = 0; i < size; ++i) {
            if(!visited[i] && cntDif(here, words[i])) {
                visited[i] = 1;
                q.push({words[i], cnt + 1});
            }
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    if(find(words.begin(), words.end(), target) == words.end()) return 0;
    return bfs(begin, target, words);
}
