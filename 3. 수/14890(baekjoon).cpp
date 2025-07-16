#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, l, ans;
int board[101][101];

vector<int> line;
bool checkLine() {
    vector<bool> used(n, false);

    for(int i = 0; i < n - 1; ++i){
        int dif = line[i + 1] - line[i];

        if(!dif) continue;
        else if (dif == 1){
            for(int j = i; j > i - l; --j) {
                if(j < 0 || line[j] != line[i] || used[j]) return false;
                used[j] = true;
            }
        }
        else if (dif == -1) {
            for(int j = i + 1; j <= i + l; ++j) {
                if(j >= n || line[j] != line[i+1] || used[j]) return false;
                used[j] = true;
            }
        }
        else return false;
    }
    return true;
}

int main() {
    FastIO;
    cin >> n >> l;
    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; ++i){
        line.clear();
        for(int j = 0; j < n; ++j) line.push_back(board[i][j]);
        if(checkLine()) ans++;
        line.clear();
        for(int j = 0; j < n; ++j) line.push_back(board[j][i]);
        if(checkLine()) ans++;
    }

    cout << ans;
    return 0;
}
