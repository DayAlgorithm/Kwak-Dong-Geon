#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int r, c, k;
int A[101][101];
int R_size = 3, C_size = 3;

bool cmp(pair<int,int>& a, pair<int,int>& b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

void R_operation() {
    int newC = 0;
    for(int i = 1; i <= R_size; ++i) {
        vector<pair<int,int>> freq;
        int count[101] = {0};
        for(int j = 1; j <= C_size; ++j) {
            if (A[i][j] != 0) count[A[i][j]]++;
        }
        for(int num = 1; num <= 100; ++num) {
            if(count[num] > 0) freq.push_back({count[num], num});
        }
        sort(freq.begin(), freq.end(), cmp);
        int idx = 1;
        for(int j = 1; j <= C_size; ++j) A[i][j] = 0;
        for(auto &p : freq){
            if (idx > 100) break; 
            A[i][idx++] = p.second;
            if (idx > 100) break;
            A[i][idx++] = p.first;
        }
        newC = max(newC, idx - 1);
    }
    C_size = newC;
    if(C_size > 100) C_size = 100;
}

void C_operation() {
    int newR = 0;
    for(int j = 1; j <= C_size; ++j){
        vector<pair<int,int>> freq;
        int count[101] = {0};
        for(int i = 1; i <= R_size; ++i) {
            if (A[i][j] != 0) count[A[i][j]]++;
        }
        for(int num = 1; num <= 100; ++num) {
            if(count[num] > 0) freq.push_back({count[num], num});
        }
        sort(freq.begin(), freq.end(), cmp);
        int idx = 1;
        for(int i = 1; i <= R_size; ++i) A[i][j] = 0;
        for(auto &p : freq){
            if (idx > 100) break;
            A[idx++][j] = p.second;
            if (idx > 100) break;
            A[idx++][j] = p.first;
        }
        newR = max(newR, idx - 1);
    }
    R_size = newR;
    if(R_size > 100) R_size = 100;
}

int main() {
    FastIO;
    cin >> r >> c >> k;
    for(int i = 1; i <= 3; ++i){
        for(int j = 1; j <= 3; ++j){
            cin >> A[i][j];
        }
    }

    int time = 0;
    while(time <= 100){
        if(A[r][c] == k) {
            cout << time;
            return 0;
        }
        if(R_size >= C_size) R_operation();
        else C_operation();
        time++;
    }

    cout << -1;
    return 0;
}
