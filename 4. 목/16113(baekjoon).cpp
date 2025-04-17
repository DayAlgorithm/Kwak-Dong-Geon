#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};

//n : 문자열의 총 길이,sign : signal, cnt : 켜진 칸 수수
int n, sign[5][20001], cnt;
int visited[5][20001];

//숫자 판별
int calcNum(int y, int x){
    if(cnt == 5) return 1; //1
    if(cnt == 7) return 7; //7
    if(cnt == 9) return 4; //4
    if(cnt == 13) return 8; //8

    //0 또는 6 또는 9
    if(cnt == 12){
        //9
        if(!visited[y + 3][x]) return 9;
        //6
        if(!visited[y + 1][x + 2]) return 6;
        //0
        return 0;
    }

    //나머지 2, 3, 5
    //2
    if(visited[y + 3][x]) return 2;
    //5
    if(visited[y + 1][x]) return 5;
    //3
    return 3;
}

int bfs(int start_y, int start_x){
    queue<pair<int, int>> q;
    q.push({start_y, start_x});
    visited[start_y][start_x] = 1;
    cnt = 1;
    while(!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i){
            int ny = y + dy[i], nx = x + dx[i];
            if(ny >= 0 && ny < 5 && nx >=0 && nx < n && sign[ny][nx] && !visited[ny][nx]){
                q.push({ny, nx});
                visited[ny][nx] = 1;
                cnt++;
            }
        }
    }
    return calcNum(start_y, start_x);
}

string solve(){
    string ret = "";
    for(int i = 0; i < n; ++i){
        if(sign[0][i] && !visited[0][i]){
            ret += to_string(bfs(0, i));
        }
    }
    return ret;
}

int main() {
    FastIO;
    string str;
    cin >> n >> str;
    n /= 5;
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < n; ++j){
            if(str[i * n + j] == '#') sign[i][j] = 1;
        }
    }
    cout << solve() << "\n";
    return 0;
}