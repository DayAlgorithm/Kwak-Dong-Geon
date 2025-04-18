#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n;
deque<int> line;
stack<int> temp;

bool move(){
    for(int i = 1; i <= n; ++i){
        //간식을 바로 받을 수 있는 경우
        if(!line.empty() && line.front() == i){
            line.pop_front();
            continue;
        }
        if(!temp.empty() && temp.top() == i){
            temp.pop();
            continue;
        }
        
        //스택에 옮겨야하는 경우
        while(!line.empty()){
            if(line.front() == i){
                line.pop_front();
                break;
            }
            //순서대로 간식을 받는게 불가능한 경우
            if(!temp.empty() && line.front() > temp.top()) return false;
            temp.push(line.front());
            line.pop_front();
        }
    }
    return true;
}

int main() {
    FastIO;
    cin >> n;
    int num;
    for(int i = 0; i < n; ++i){
        cin >> num;
        line.push_back(num);
    }
    if(move()) cout << "Nice\n";
    else cout << "Sad\n";
    return 0;
}