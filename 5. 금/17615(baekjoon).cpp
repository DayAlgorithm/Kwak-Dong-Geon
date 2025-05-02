#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;                    

int n, ans = 987654321;
string str;

int main() {
    FastIO;
    cin >> n >> str;
    int cnt = 0, sum = 0;
    for(auto boll: str){    //빨간공 오른쪽으로 이동동
        if(boll == 'R') cnt++;
        else{
            sum += cnt;
            cnt = 0;
        }
    }
    ans = min(ans, sum);
    sum = 0; cnt = 0;
    for(auto boll: str){    //파란공 오른쪽으로 이동동
        if(boll == 'B') cnt++;
        else{
            sum += cnt;
            cnt = 0;
        }
    }
    ans = min(ans, sum);
    sum = 0; cnt = 0;
    for(int i = n - 1; i >= 0; --i){    //빨간공 왼쪽으로 이동동
        if(str[i] == 'R') cnt++;
        else{
            sum += cnt;
            cnt = 0;
        }
    }
    ans = min(ans, sum);
    sum = 0; cnt = 0;
    for(int i = n - 1; i >= 0; --i){    //파랑공 오른쪽으로 이동동
        if(str[i] == 'B') cnt++;
        else{
            sum += cnt;
            cnt = 0;
        }
    }
    ans = min(ans, sum);
    cout << ans;
    return 0;
}