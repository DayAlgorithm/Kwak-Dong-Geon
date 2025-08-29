#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
    if(a + b > b + a) return true;
    return false;
}

string solution(vector<int> numbers) {
    string ans = "";
    vector<string> num;
    for(auto n : numbers){
        num.push_back(to_string(n));
    }
    sort(num.begin(), num.end(), compare);
    if(num[0] == "0") return "0";
    for(auto n : num) ans += n;
    return ans;
}