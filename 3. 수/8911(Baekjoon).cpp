#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

//이동 방향향
const int d[4] = {1, 1, -1, -1};

//t : 테스트 케이스, MY = max Y, mY = min y, dir : 방향향
int t, mY, MY, y, mX, MX, x, dir;
string order;

//움직이는 함수수
void move(){
    for(int i = 0; i < order.size(); ++i){
        //앞으로 한칸칸
        if(order[i] == 'F'){
            if(dir == 0 || dir == 2){
                y += d[dir];
                if(y > 0 && MY < y) MY = y;
                else if(y < 0 && abs(mY) < abs(y)) mY = y;
            }
            else if(dir == 1 || dir == 3){
                x += d[dir];
                if(x > 0 && MX < x) MX = x;
                else if(x < 0 && abs(mX) < abs(x)) mX = x;
            }
        }
        //뒤로 한칸칸
        else if(order[i] == 'B'){
            if(dir == 0 || dir == 2){
                y -= d[dir];
                if(y > 0 && MY < y) MY = y;
                else if(y < 0 && abs(mY) < abs(y)) mY = y;
            }
            else if(dir == 1 || dir == 3){
                x -= d[dir];
                if(x > 0 && MX < x) MX = x;
                else if(x < 0 && abs(mX) < abs(x)) mX = x;
            }
        }
        //시계방향
        else if(order[i] == 'R'){
            dir = (dir + 1) % 4;
        }
        //반시계 방향향
        else{
            dir = (dir + 3) % 4;
        }
    }
}

int main() {
    FastIO;
    cin >> t;
    while(t--){
        //변수 초기화화
        MY = mY = MX = mX = y = x = 0;
        cin >> order;
        move();
        cout << (MY - mY) * (MX - mX) << "\n";
    }
    return 0;
}