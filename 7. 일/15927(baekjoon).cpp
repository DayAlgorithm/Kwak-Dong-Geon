#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

string str;

bool allSame() {
    for (int i = 1; i < str.size(); ++i) {
        if (str[i] != str[0]) return false;
    }
    return true;
}

bool isPalindrome() {
    int l = 0, r = str.size() - 1;
    while(l < r){
        if(str[l] != str[r]) return false;
        ++l; --r;
    }
    return true;
}

int main() {
    FastIO;
    cin >> str;

    if(allSame()) cout << -1;
    else if(!isPalindrome()) cout << str.size();
    else cout << str.size() - 1;

    return 0;
}
