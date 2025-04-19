#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n;
priority_queue<int> pq;

int main() {
    FastIO;
    cin >> n;
    int num;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> num;
            //큐에 아직 n개 이하의 숫자만 있는경우
            if(pq.size() < n) pq.push(-num);
            else if(num > -pq.top()){   //큐에 n개의 원소가 있고, 가장 작은 값보다 입력 받은 숫자가 큰 경우우
                pq.pop();
                pq.push(-num);
            }
        }
    }
    cout << -pq.top();
    return 0;
}