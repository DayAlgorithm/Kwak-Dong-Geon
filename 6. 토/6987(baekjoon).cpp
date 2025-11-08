#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int result[6][3];
int win[6], draw[6], lose[6];
bool isPossible;
vector<pair<int,int>> games;

void dfs(int idx){
    if(isPossible) return;
    
    if(idx == 15){
        for(int i = 0; i < 6; ++i) {
            if(win[i] != 0 || draw[i] != 0 || lose[i] != 0){
                return;
            }
        }
        isPossible = true;
        return;
    }
    
    int home = games[idx].first, away = games[idx].second;
    
    if(win[home] > 0 && lose[away] > 0){
        win[home]--;
        lose[away]--;
        dfs(idx + 1);
        win[home]++;
        lose[away]++;
    }
    
    if(draw[home] > 0 && draw[away] > 0){
        draw[home]--;
        draw[away]--;
        dfs(idx + 1);
        draw[home]++;
        draw[away]++;
    }
    
    if(lose[home] > 0 && win[away] > 0){
        lose[home]--;
        win[away]--;
        dfs(idx + 1);
        lose[home]++;
        win[away]++;
    }
}

int main() {
    FastIO;
    
    for(int i = 0; i < 6; ++i){
        for(int j = i + 1; j < 6; ++j){
            games.push_back({i, j});
        }
    }

    for(int t = 0; t < 4; ++t){
        for(int i = 0; i < 6; ++i){
            cin >> win[i] >> draw[i] >> lose[i];
        }
        
        isPossible = false;
        
        int totalWin = 0, totalDraw = 0, totalLose = 0;
        for(int i = 0; i < 6; ++i){
            totalWin += win[i];
            totalDraw += draw[i];
            totalLose += lose[i];
        }
    
        if(totalWin == totalLose && totalDraw % 2 == 0) dfs(0);

        cout << (isPossible ? 1 : 0) << " ";
    }
    
    return 0;
}
