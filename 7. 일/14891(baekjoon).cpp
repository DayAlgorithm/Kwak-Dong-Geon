#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

deque<int> gear[4];
bool rotated[4];
int k;

//기어 회전
void rotate(int num, int dir){
    if(rotated[num]) return;    //이미 움직인 기어인 경우
    int three = gear[num][2], six = gear[num][6];   //왼쪽, 오른쪽 접촉 기어 상태 저장
    if(dir == 1){   //시계 방향
        gear[num].push_front(gear[num].back());
        gear[num].pop_back();
    } else {    //반시계 방향
        gear[num].push_back(gear[num].front());
        gear[num].pop_front();
    }
    rotated[num] = true;
    int left = num - 1, right = num + 1;
    if(left >= 0 && six != gear[left][2]) rotate(left, -dir);   //왼쪽 기어가 같이 움직이는 경우
    if(right < 4 && three != gear[right][6]) rotate(right, -dir);   //오른쪽 기어가 같이 움직이는 경우
}

//점수 계산산
int calcScore(){
    int ret = 0;
    for(int i = 0; i < 4; ++i){
        if(gear[i].front() == 1) ret += pow(2, i);
    }
    return ret;
}

int main() {
    FastIO;
    for(int i = 0; i < 4; ++i){
        string str;
        cin >> str;
        for(int j = 0; j < 8; ++j){
            gear[i].push_back(str[j] - '0');
        }
    }
    cin >> k;
    int num, dir;
    for(int i = 0; i < k; ++i){
        cin >> num >> dir;
        memset(rotated, false, sizeof(rotated));
        rotate(num - 1, dir);
    }
    cout << calcScore() << "\n";
    return 0;
}