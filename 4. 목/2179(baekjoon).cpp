#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n, cnt;
pair<string, string> ans;
vector<string> words;

void findAns(int start){
    for(int i = start + 1; i < n; ++i){
        int idx = 0;
        while(words[start][idx] == words[i][idx]) idx++;
        if(cnt < idx){
            cnt = idx;
            ans = {words[start], words[i]};
        }
    }
}

int main(){
    FastIO;
    cin >> n;
    words = vector<string>(n);
    for(int i = 0; i < n; ++i){
        cin >> words[i];
    }
    for(int i = 0; i < n; ++i){
        findAns(i);
    }
    cout << ans.first << "\n" << ans.second;
    return 0;
}