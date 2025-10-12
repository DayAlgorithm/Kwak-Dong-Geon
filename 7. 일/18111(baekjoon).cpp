#include<bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m, b;
int ground[501][501];
int minHieght = INT_MAX, maxHieght = -INT_MAX;

int flattening(int hieght, int blocks){
    int ret = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int dif = hieght - ground[i][j];
            if(dif > 0){
                blocks -= dif;
                ret += dif;
            }
            else if(dif < 0){
                blocks -= dif;
                ret -= 2 * dif;
            }
            
        }
    }
    if(blocks < 0) return INT_MAX;
    return ret;
}

int main(){
    FastIO;
    cin >> n >> m >> b;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> ground[i][j];
            if(ground[i][j] > maxHieght) maxHieght = ground[i][j];
            if(ground[i][j] < minHieght) minHieght = ground[i][j];
        }
    }
    int minCost = INT_MAX, ans;
    for(int i = maxHieght; i >= minHieght; --i){
        int cost = flattening(i, b); 
        if(minCost > cost){
            minCost = cost;
            ans = i;
        }
    }
    cout << minCost << " " << ans << "\n";
    return 0;
}