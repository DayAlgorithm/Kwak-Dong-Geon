#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n;
char board[7][7];
vector<pair<int,int>> teachers, empties;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
bool watch(int x, int y, int d){
    while(true){
        x += dx[d];
        y += dy[d];
        if(x < 0 || y < 0 || x >= n || y >= n || board[x][y] == 'O') return true;
        if(board[x][y] == 'S') return false;
    }
}

bool check(){
    for(auto t : teachers){
        if(!watch(t.first, t.second, 0)) return false;
        if(!watch(t.first, t.second, 1)) return false;
        if(!watch(t.first, t.second, 2)) return false;
        if(!watch(t.first, t.second, 3)) return false;
    }
    return true;
}

int main() {
    FastIO;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            if(board[i][j] == 'T') teachers.push_back({i,j});
            else if(board[i][j] == 'X') empties.push_back({i,j});
        }
    }

    for(int i = 0; i < (int)empties.size() - 2; i++){
        for(int j = i + 1; j < (int)empties.size() - 1; j++){
            for(int k = j + 1; k < (int)empties.size(); k++){
                board[empties[i].first][empties[i].second] = 'O';
                board[empties[j].first][empties[j].second] = 'O';
                board[empties[k].first][empties[k].second] = 'O';

                if(check()){
                    cout << "YES\n";
                    return 0;
                }

                board[empties[i].first][empties[i].second] = 'X';
                board[empties[j].first][empties[j].second] = 'X';
                board[empties[k].first][empties[k].second] = 'X';
            }
        }
    }
    cout << "NO\n";
    return 0;
}
