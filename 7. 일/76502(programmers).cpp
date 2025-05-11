#include <bits/stdc++.h>

using namespace std;

const string open("({["), close(")}]");

//올바른 문자열이면 1, 아니면 0 반환환
int correct(string& str){
    stack<char> s;
    for(auto& i : str){
        if(open.find(i) != -1) s.push(i);   //여는 괄호는 스택에 넣기
        else if(close.find(i) != -1){   //닫는 괄호인 경우 스택 확인
            if(s.empty()) return 0;
            if(open.find(s.top()) != close.find(i)) return 0;
            s.pop();
        }
    }
    if(s.empty()) return 1;
    return 0;
}

int solution(string s) {
    int answer = 0;
    for(int i = 0; i < s.size(); ++i){
        //문자열 한칸씩 회전전
        rotate(s.begin(), s.begin() + 1, s.end());
        answer += correct(s);
    }
    return answer;
}