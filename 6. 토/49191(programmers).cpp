#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;

int floyd(int n){
    int cnt = n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            for(int k = 1; k <= n; ++k){
                if(adj[i][j] == 1 && adj[j][k] == 1){   //i가 j 한테 이기고 j가 k 한테 이기면 i는 k한테 이기며 k는 i 한테 진다.
                    adj[i][k] = 1;
                    adj[k][i] = -1;
                }
                else if(adj[i][j] == -1 && adj[j][k] == -1){    //i가 j 한테 지고 j가 k 한테 지면 i는 k한테 지며 k는 i 한테 이긴다.
                    adj[i][k] = -1;
                    adj[k][i] = 1;
                }
            }
        }
    }
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <=n; ++j){
            if(i != j && !adj[i][j]){   //승패를 알수 없는 선수가 존재하는 경우
                cnt--;
                break;
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    adj = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    for(int i = 0; i < results.size(); ++i){    //i가 j 한테 이기면 1 지면 -1
        adj[results[i][0]][results[i][1]] = 1;
        adj[results[i][1]][results[i][0]] = -1;
    }
    answer = floyd(n);
    return answer;
}