#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

const int dx[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
const int dy[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

int n, m, a[51][51];
vector<pair<int, int>> moves;

int main() {
    FastIO;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < m; ++i){
        int d, s;
        cin >> d >> s;
        moves.emplace_back(make_pair(d, s));
    }
    
    vector<pair<int, int>> clouds;
    clouds.emplace_back(make_pair(n, 1));
    clouds.emplace_back(make_pair(n, 2));
    clouds.emplace_back(make_pair(n-1, 1));
    clouds.emplace_back(make_pair(n-1, 2));

    for(auto [d, s] : moves){
        set<pair<int, int>> flag;
        for(auto &[x, y] : clouds){
            x = ((x - 1 + dx[d] * s) % n + n) % n + 1;
            y = ((y - 1 + dy[d] * s) % n + n) % n + 1;
            a[x][y]++;
            flag.insert({x, y});
        }
        
        for(auto [x, y] : clouds){
            int cnt = 0;
            for(int dir = 2; dir <= 8; dir += 2){
                int nx = x + dx[dir], ny = y + dy[dir];
                if(nx >= 1 && nx <= n && ny >= 1 && ny <= n && a[nx][ny] > 0){
                    cnt++;
                }
            }
            a[x][y] += cnt;
        }
        
        clouds.clear();
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(a[i][j] >= 2 && flag.find({i, j}) == flag.end()){
                    clouds.emplace_back(make_pair(i, j));
                    a[i][j] -= 2;
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            ans += a[i][j];
        }
    }
    
    cout << ans;
    return 0;
}
