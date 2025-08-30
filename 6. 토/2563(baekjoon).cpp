#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, board[100][100], sum;

int main(){
    FastIO;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int left, bottom;
        cin >> left >> bottom;
        for(int y = 0; y < 10; ++y){
            for(int x = 0; x < 10; ++x){
                board[x + left][y + bottom] = 1;
            }
        }
    } 
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < 100; ++j){
            sum += board[i][j];
        }
    }
    cout << sum;
    return 0;
}