#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n, m;
vector<int> box[51];
bool used[51];

int cntMin(){
    int ret = 51;
    //조커 박스 하나식 모두 해보기기
    for(int i = 0; i < n; ++i){
        //사용 색 정보 초기화화
        memset(used, false, sizeof(used));
        int cnt = 0;
        //박스 하나식 돌면서 현재 포함 색의 개수 확인인
        for(int j = 0; j < n; ++j){
            if(i == j) continue;
            //비어있는 경우 패스스
            if(box[j].empty()) continue;
            //하나인 경우 사용했는지 여부 확인 후 cnt
            if(box[j].size() == 1){
                if(used[box[j][0]]) cnt++;
                else used[box[j][0]] = true;
            }
            //2개 이상인 경우 cnt
            else cnt++;
        }
        ret = min(ret, cnt);
    }
    return ret;
}

int main(){
    FastIO;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int num;
            cin >> num;
            if(num) box[i].push_back(j);
        }
    }
    cout << cntMin();
    return 0;
}