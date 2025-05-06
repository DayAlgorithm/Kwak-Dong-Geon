#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int dy[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
const int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int r, c, y, x, cnt;
vector<string> board;
queue<int> mov;
map<pair<int, int>, int> crazy; //미친 아두이노 위치 저장장

bool move(){
    while(!mov.empty()){
        cnt++;
        int d = mov.front() - 1;
        mov.pop();
        y += dy[d]; x += dx[d];
        if (crazy.count({y, x})) return false;  //미친 아두이노와 만난 경우
        map<pair<int, int>, int> temp;
        for(auto& i : crazy){
            int ry = i.first.first, rx = i.first.second;
            //y좌표 이동
            if(ry > y) ry--;
            else if(ry < y) ry++;
            //x좌표 이동
            if(rx > x) rx--;
            else if(rx < x) rx++;
            //미친 아두이노가 잡은 경우
            if(ry == y && rx == x) return false;
            temp[{ry, rx}]++;
        }
        crazy.clear();
        for(auto& i : temp){
            if(i.second == 1){  //미친 아두이노가 한칸에 하나만 있는 경우
                crazy[{i.first}] = 1;
            }
        }
    }
    return true;
}

int main(){
    FastIO;
    cin >> r >> c;
    board = vector<string>(r);
    for(int i = 0; i < r; ++i){
        cin >> board[i];
        for(int j = 0; j < c; ++j){
            //I, R 위치를 저장
            if(board[i][j] == 'R') crazy[{i, j}]++;
            else if(board[i][j] == 'I'){
                y = i;
                x = j;
            }
        }
    }
    string order;
    cin >> order;
    for(int i = 0; i < order.size(); ++i){
        mov.push(order[i] - '0');
    }
    if(move()){
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(i == y && j == x) cout << "I";
                else if(crazy[{i, j}]) cout << "R";
                else cout << ".";
            }
            cout << "\n";
        }
    }
    else{
        cout << "kraj " << cnt << "\n";
    }
    return 0;
}