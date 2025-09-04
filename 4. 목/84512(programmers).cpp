#include <bits/stdc++.h>
using namespace std;

const vector<char> alpha = {'A', 'E', 'I', 'O', 'U'};

int dfs(const string& word){
    int ret = 0;
    stack<string> s;
    s.push("");

    while(!s.empty()){
        string now = s.top();
        s.pop();
        if(now == word) return ret;
        ret++;

        if(now.size() < 5){
            for(int i = 0; i < alpha.size(); ++i){
                s.push(now + alpha[alpha.size() - 1 - i]);
            }
        }
    }
    return -1;
}

int solution(string word) {
    return dfs(word);
}
