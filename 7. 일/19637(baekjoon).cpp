#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n, m;
vector<pair<int, string>> style;

//이분탐색
void findStyle(int num){
    int left = 0, right = style.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(style[mid].first == num){    //조금 더 최적화 하려고 넣은 로직
            cout << style[mid].second << "\n";
            return;
        }
        if(style[mid].first < num){ //현재 인덱스의 값이 num 보다 작은 경우
            left = mid + 1;
        }
        else{   //num 보다 크거나 같은 경우
            right = mid - 1;
        }
    }

    if(left == 0){ 
        cout << style[0].second << "\n";
    } 
    else if(left == style.size()){
        cout << style[style.size() - 1].second << "\n";
    } 
    else{
        cout << style[left].second << "\n";
    }
}

int main() {
    FastIO;
    cin >> n >> m;
    string str;
    int num;
    for(int i = 0; i < n; ++i){
        cin >> str >> num;
        //같은 값이 들어있는 경우를 넣지 않음
        if(style.empty() || style.back().first != num) style.push_back({num, str}); 
    }
    for(int j = 0; j < m; ++j){
        cin >> num;
        findStyle(num);
    }
    return 0;
}