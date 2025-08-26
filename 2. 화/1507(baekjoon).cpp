#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, ans, dis[21][21], path[21][21];

bool floyd(){
	for(int k = 0; k < n; ++k){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(k == i || k == j) continue;
				if(dis[i][j] > dis[i][k] + dis[k][j]) return false;
				else if(dis[i][j] == dis[i][k] + dis[k][j]) path[i][j] = 0;
			}
		}
	}
    return true;
}

int main(){
    FastIO;
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> dis[i][j];
            path[i][j] = dis[i][j];
        }
    }
    if(!floyd()) cout << -1;
    else{
        int sum = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                sum += path[i][j];
            }
        }
        cout << sum / 2;
    }
    return 0;
}