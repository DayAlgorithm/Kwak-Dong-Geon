#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int n;
vector<vector<int>> classroom;
vector<set<int>> prefer(401);

int main(){
    FastIO;
    cin >> n;
    classroom.resize(n, vector<int>(n, 0));
    for(int i = 0; i < n*n; ++i){
        int num;
        cin >> num;
        for(int j = 0; j < 4; ++j){
            int like;
            cin >> like;
            prefer[num].insert(like);
        }

        int maxLike = -1, maxEmpty = -1;
        int row = -1, col = -1;

        for(int r = 0; r < n; ++r){
            for(int c = 0; c < n; ++c){
                if(classroom[r][c] != 0) continue;

                int likeCnt = 0;
                int emptyCnt = 0;

                for(int j = 0; j < 4; ++j){
                    int nr = r + dx[j], nc = c + dy[j];
                    if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                    if(classroom[nr][nc] == 0) emptyCnt++;
                    else if(prefer[num].count(classroom[nr][nc])) likeCnt++;
                }

                if(likeCnt > maxLike || (likeCnt == maxLike && emptyCnt > maxEmpty) ||
                   (likeCnt == maxLike && emptyCnt == maxEmpty && (r < row || (r == row && c < col)))){
                    maxLike = likeCnt;
                    maxEmpty = emptyCnt;
                    row = r;
                    col = c;
                }
            }
        }
        classroom[row][col] = num;
    }

    int ans = 0;
    for(int r = 0; r < n; ++r){
        for(int c = 0; c < n; ++c){
            int num = classroom[r][c], likeCnt = 0;
            for(int j = 0; j < 4; ++j){
                int nr = r + dx[j], nc = c + dy[j];
                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if(prefer[num].count(classroom[nr][nc])) likeCnt++;
            }
            if(likeCnt > 0) ans += pow(10, likeCnt - 1);
        }
    }
    cout << ans;
    return 0;
}