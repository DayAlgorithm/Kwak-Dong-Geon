#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int t, n;
vector<string> ans;

void dfs(int num, string s) {
    if(num == n+1) {
        string expr = "";
        for(char c : s) {
            if(c == ' ') continue;
            expr.push_back(c);
        }

        vector<int> values;
        int i = 0;
        while(i < (int)expr.size()) {
            int val = 0;
            int sign = 1;
            if (expr[i] == '+' || expr[i] == '-') {
                if (expr[i] == '-') sign = -1;
                i++;
            }
            while (i < (int)expr.size() && isdigit(expr[i])) {
                val = val * 10 + (expr[i] - '0');
                i++;
            }
            values.push_back(val * sign);
        }
        int res = 0;
        for(int v : values) res += v;
        if(res == 0) ans.push_back(s);
        return;
    }

    dfs(num+1, s + " " + to_string(num));
    dfs(num+1, s + "+" + to_string(num));
    dfs(num+1, s + "-" + to_string(num));
}

int main(){
    FastIO;
    cin >> t;
    while(t--){
        ans.clear();
        cin >> n;
        dfs(2, "1");
        sort(ans.begin(), ans.end());
        for(auto &s : ans) cout << s << "\n";
        cout << "\n";
    }
    return 0;
}
