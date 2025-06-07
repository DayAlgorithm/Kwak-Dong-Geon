#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n, m;
int digree[1001];
vector<vector<int>> adj;

int cache[1001];
int cnt(int idx){
    int& ret = cache[idx];
    if(ret != -1) return ret;
    ret = 1;

    if(digree[idx]){    //선이수 과목이 있는 경우
        int maxCnt = 1; //선이수 과목중 수강하기 위해 가장 많은 학기가 필요한 과목 찾기기
        for(auto there : adj[idx]){ 
            maxCnt = max(maxCnt, cnt(there));
        }
        ret += maxCnt;
    }

    return ret;
}

int main(){
    FastIO;
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);
    int a, b;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        adj[b].push_back(a);
        digree[b]++;    //차수 cnt
    }
    memset(cache, -1, sizeof(cache));
    for(int i = 1; i <= n; ++i){
        cout << cnt(i) << " ";
    }
    return 0;
}