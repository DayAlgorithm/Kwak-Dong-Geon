#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;


int n, k, alpha, ans;
vector<int> words;


void dfs() {
    stack<tuple<int, int, int>> s;
    s.push({0, 5, alpha});
    while(!s.empty()){
        int idx = get<0>(s.top()), cnt = get<1>(s.top()), alpha = get<2>(s.top());
        s.pop();
        if(cnt == k){
            int temp = 0;
            for(int word : words){
                if( (word & alpha) == word ) ++temp;
            }
            ans = max(ans, temp);
            continue;
        }
        for(int i = idx; i < 26; ++i){
            if(alpha & (1 << i)) continue;
            s.push({i + 1, cnt + 1, alpha | (1 << i)});
        }
    }
}

int main(){
    FastIO;
    cin >> n >> k;
    words.resize(n);
    string s;
    alpha |= (1 << ('a' - 'a'));
    alpha |= (1 << ('c' - 'a'));
    alpha |= (1 << ('i' - 'a'));
    alpha |= (1 << ('n' - 'a'));
    alpha |= (1 << ('t' - 'a'));

    for(int i = 0; i < n; ++i){
        cin >> s;
        int mask = 0;
        for(char ch : s) mask |= (1 << (ch - 'a'));
        words[i] = mask;
    }
    if(k < 5){
        cout << 0;
        return 0;
    }
    dfs();
    cout << ans;
    return 0;
}
