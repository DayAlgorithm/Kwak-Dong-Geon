#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = 2147483647;

int t, n;

int main() {
    FastIO;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> arr(n);
        map<int, int> team;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            team[arr[i]]++;    //팀별 인원수 세기
        }
        //5명 이하인 팀 제외
        int point = 1;
        map<int, vector<int>> score;    //팀별 등수 저장
        for(int i = 0; i < n; ++i){
            if(team[arr[i]] == 6){
                score[arr[i]].push_back(point);
                point++;
            } 
        }
        int win = -1, winScore = INF;
        for(auto teams : score){
            int scoreSum = 0;
            for(int i = 0; i < 4; ++i){
                scoreSum += teams.second[i];
            }
            if(scoreSum < winScore){
                win = teams.first;
                winScore = scoreSum;
            }
            else if(scoreSum == winScore && teams.second[4] < score[win][4]){
                win = teams.first;
                winScore = scoreSum;
            }
        }
        cout << win << "\n";
    }    
    return 0;
}