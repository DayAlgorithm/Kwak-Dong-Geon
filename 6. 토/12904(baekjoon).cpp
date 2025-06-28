#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

string s, t;

int main(){
    FastIO;
    cin >> s >> t;
    while(true){
		if(t[t.size() - 1] == 'A') t.pop_back();
		else {
			t.pop_back();
			reverse(t.begin(), t.end());
		}
		if(t.size() == s.size()){
			if(t == s) cout << 1;
			else cout << 0;
			break;
		}
	}
    return 0;
}