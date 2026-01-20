#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, ans = 0;
int inning[51][9];
int order[9];
bool used[9];

int calc() {
    int score = 0;
    int idx = 0;
    
    for (int inn = 0; inn < n; ++inn) {
        int cnt = 0;
        bool base[3] = {false, false, false};
        
        while (cnt < 3) {
            int player = order[idx];
            int result = inning[inn][player];

            if (result == 0) {
                cnt++;
            } else if (result == 1) {
                if (base[2]) {
                    score++;
                    base[2] = false;
                }
                if (base[1]) {
                    base[2] = true;
                    base[1] = false;
                }
                if (base[0]) {
                    base[1] = true;
                    base[0] = false;
                }
                base[0] = true;
            } else if (result == 2) {
                if (base[2]) {
                    score++;
                    base[2] = false;
                }
                if (base[1]) {
                    score++;
                    base[1] = false;
                }
                if (base[0]) {
                    base[2] = true;
                    base[0] = false;
                }
                base[1] = true;
            } else if (result == 3) {
                for (int i = 0; i < 3; ++i) {
                    if (base[i]) {
                        score++;
                        base[i] = false;
                    }
                }
                base[2] = true;
            } else if (result == 4) {
                for (int i = 0; i < 3; ++i) {
                    if (base[i]) {
                        score++;
                        base[i] = false;
                    }
                }
                score++;
            } 
            idx = (idx + 1) % 9;
        }
    }
    
    return score;
}

void dfs(int idx) {
    if (idx == 9) {
        ans = max(ans, calc());
        return;
    }
    
    if (idx == 3) {
        order[idx] = 0;
        dfs(idx + 1);
        return;
    }
    
    for (int p = 1; p < 9; ++p) {
        if (used[p]) continue;
        used[p] = true;
        order[idx] = p;
        dfs(idx + 1);
        used[p] = false;
    }
}

int main() {
    FastIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> inning[i][j];
        }
    }

    used[0] = true;
    dfs(0);
    
    cout << ans;
    return 0;
}
