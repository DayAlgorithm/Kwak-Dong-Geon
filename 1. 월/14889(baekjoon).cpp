#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, ans = INT_MAX;
int score[21][21];
bool used[21];

void calcSum(){
    int sumA = 0, sumB = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i == j) continue;
            if(used[i] && used[j]) sumA += score[i][j];
            else if(!used[i] && !used[j]) sumB += score[i][j];
        }
    }
    ans = min(abs(sumA - sumB), ans);
}

void makeTeam(int cnt, int idx){
    if(cnt == n / 2) calcSum();

    for(int i = idx; i <= n; ++i){
        used[i] = true;
        makeTeam(cnt + 1, i + 1);
        used[i] = false;    
    }
}

int main() {
    FastIO;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> score[i][j];
        }
    }
    makeTeam(0, 1);
    cout << ans << "\n";
    return 0;
}
