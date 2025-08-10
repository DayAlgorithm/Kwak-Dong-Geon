#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int t;

bool recursive(string s) {
	bool flag = false;
	int size = s.size();
	if(size == 0) return true;

	if(s[0] == '0'){
        if(s[1] == '1') flag |= recursive(s.substr(2));
    }	
	else{
		int i = 1;
		while(i < size && s[i] == '0') i++;

		if(i <= 2) return flag;
 
		int j = i;
		while(j < size && s[j] == '1') j++;

		if(j == i + 1) flag |= recursive(s.substr(j));

		if(j >= i + 2){
			if(j == size - 1) return flag;
			if(j + 1 < size && s[j + 1] == '0')  flag |= recursive(s.substr(j-1));
			else flag |= recursive(s.substr(j));
		}
	}
	return flag;
}

int main(){
    FastIO;
    cin >> t;
    while(t--){
        string n; 
        cin >> n;
		string ans = (recursive(n)) ? "YES" : "NO";
		cout << ans << "\n";
    }
    return 0;
}

