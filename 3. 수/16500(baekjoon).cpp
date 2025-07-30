#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
string str;
vector<string> words;

bool makeWord(){
    int size = str.size();
    vector<bool> word(size + 1, false);
    word[size] = true;
    
    for(int i = size - 1; i >= 0; --i) {
        for(auto& w : words) {
            int len = w.size();
            if(i + len <= size && str.substr(i, len) == w){
                if(word[i + len]){
                    word[i] = true;
                    break;
                }
            }
        }
    }
    return word[0];
}

int main(){
    FastIO;
    cin >> str >> n;
    words.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> words[i];
    }
    cout << makeWord();
    return 0;
}
