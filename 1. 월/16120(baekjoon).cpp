#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string str;
stack<char> s;

int main(){
    FastIO;
    cin >> str;
    bool flag = false, ans = true;
    for(auto c : str){
        if(flag){
            if(c == 'A' || s.size() < 3){
                ans =false;
                break;
            }
            s.pop();
            s.pop();
            s.pop();
            s.push('P');
            ans = true;
            flag = false;
        }
        else{
            if(c == 'A'){
                ans = false;
                flag = true;
            }
            s.push(c);
        }
    }
    if(ans && s.size() == 1) cout << "PPAP";
    else cout << "NP";
    return 0;
}