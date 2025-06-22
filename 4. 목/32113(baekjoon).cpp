#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, r, c;
bool pizza[51][51] = {false, };
vector<string> ans;

int main(){
    FastIO;
    cin >> n >> r >> c;
    for(int i = 1; i <= n; ++i){
        char a;
        for(int j = 1; j <= n; ++j){
            cin >> a;
            if(a == '#'){
                pizza[i][j] = true;
            }
        }
    }
    //r행 채우고 1열 채우기
    for(int i = 1; i < c; ++i){
        ans.push_back("L " + to_string(r) + " push");
    }
    for(int i = n; i > c; --i){
        ans.push_back("R " + to_string(r) + " push");
    }
    for(int i = 1; i < r; ++i){
        ans.push_back("U " + to_string(1) + " push");
    }
    for(int i = n; i > r; --i){
        ans.push_back("D " + to_string(1) + " push");
    }

    //(r, c) 위 채우기
    for(int i = r - 1; i >= 1; --i){
        for(int j = 2; j <= n; ++j){
            ans.push_back("R " + to_string(i) + " push");
        }
        for(int j = 2; j <= n; ++j){
            if(!pizza[i][j]) ans.push_back("U " + to_string(j) + " pull");
        }
    }

    //(r, c) 아래 채우기
    for(int i = r; i <= n; ++i){
        for(int j = 2; j <= n; ++j){
            if(i == r) break;
            ans.push_back("R " + to_string(i) + " push");
        }
        for(int j = 2; j <= n; ++j){
            if(!pizza[i][j]) ans.push_back("D " + to_string(j) + " pull");
        }
    }
    
    //1열 정리
    for(int i = 1; i <= n; ++i){
        if(!pizza[i][1]) ans.push_back("L " + to_string(i) + " pull");
    }

    cout << ans.size() << "\n";
    for(auto a: ans){
        cout << a << "\n";
    }
    return 0;
}