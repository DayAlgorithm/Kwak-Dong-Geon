#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

// H = 1, C = 12, O = 16

string str;
stack<int> s;

int main() {
    FastIO;
    cin >> str;
    for(auto &ch : str) {
        if(ch == 'H') s.push(1);
        else if(ch == 'C') s.push(12);
        else if(ch == 'O') s.push(16);
        else if(ch >= '2' && ch <= '9') {
            int top = s.top();
            s.pop();
            s.push(top * (ch - '0'));
        }
        else if(ch == '(') s.push(-1);
        else if(ch == ')') {
            int temp = 0;
            while(!s.empty() && s.top() != -1) {
                temp += s.top();
                s.pop();
            }
            if(!s.empty() && s.top() == -1) s.pop();
            s.push(temp);
        }
    }
    int ans = 0;
    while(!s.empty()) {
        ans += s.top();
        s.pop();
    }
    cout << ans;
    return 0;
}