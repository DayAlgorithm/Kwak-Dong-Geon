#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = 987654321;

int n, cnt;
pair<int, int> ans = {INF, INF};
vector<string> words;

void findAns(){
    for(int i = 100; i >= 0; --i){
        map<string, vector<int>> m;
        for(int j = 0; j < n; ++j){
            if(words[j].size() < i) continue;
            string sub = words[j].substr(0, i);
            if(m.count(sub)) ans = min(ans, {m[sub][0], j});
            m[sub].push_back(j);
        }
        if(ans.first != INF) return;
    }
}

int main(){
    FastIO;
    cin >> n;
    words = vector<string>(n);
    for(int i = 0; i < n; ++i){
        cin >> words[i];
    }
    findAns();
    cout << words[ans.first] << "\n" << words[ans.second];
    return 0;
}