#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int x, cnt;
string word, t;

int main() {
    FastIO;
    cin >> x >> word;
    int n = word.size();
    int c = n / 2;
    t = word;

    while(true){
        string temp = "";
        cnt++;
        for(int i = 0; i <= c; i++){
            temp += t[i];
            if(word[n - 1 - i]) temp += t[n - 1 - i];
        }
        for(int i = 0; i < n; i++) t[i] = temp[i];
        if(word == t) break;
    }

    x %= cnt;
    while(x--){
        int l = 0, r = n - 1;
        string new_word = word;
        for(int i = 0; i < n; i++){
            if(i % 2) new_word[r--] = word[i];
            else new_word[l++] = word[i];
        }
        word = new_word;
    }

    cout << word;
    return 0;
}
