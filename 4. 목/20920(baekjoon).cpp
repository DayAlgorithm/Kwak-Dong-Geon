#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m;
map<string, int> cnt;

int main(){
    FastIO;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        if(s.length() >= m) cnt[s]++;
    }
    vector<pair<string, int>> ans(cnt.begin(), cnt.end());
    //정렬 함수 정의
	sort(ans.begin(), ans.end(), [](pair<string,int> const& left, pair<string, int> const& right){
			if(left.second != right.second) return left.second > right.second;  //빈도수가 다르면 
            else if(left.first.length() != right.first.length()){   //단어의 길이
                return left.first.length() > right.first.length();
            }
            else return left.first < right.first;   //사전순
		});
    for(auto& a : ans){
        cout << a.first << "\n";
    }
    return 0;
}


