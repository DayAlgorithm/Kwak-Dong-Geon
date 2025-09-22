#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int t;
int main(){
    FastIO;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> phone(n);
        for(int i = 0; i < n; ++i){
            cin >> phone[i];
        }
        sort(phone.begin(), phone.end());
        bool flag = true;
        for(int i = 0; i < phone.size() - 1; ++i){
            if(!phone[i + 1].find(phone[i])) flag = false;
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}