#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

deque<int> gear[4];
bool rotated[4];
int k;

void rotate(int num, int dir){
    if(rotated[num]) return;
    int three = gear[num][2], six = gear[num][6];
    if(dir == 1){
        gear[num].push_front(gear[num].back());
        gear[num].pop_back();
    } else {
        gear[num].push_back(gear[num].front());
        gear[num].pop_front();
    }
    rotated[num] = true;
    int left = num - 1, right = num + 1;
    if(left >= 0 && six != gear[left][2]) rotate(left, -dir);
    if(right < 4 && three != gear[right][6]) rotate(right, -dir);
}

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
