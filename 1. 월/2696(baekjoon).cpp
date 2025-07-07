#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int t, m;

int main(){
    FastIO;
    cin >> t;
    while(t--){
        vector<long long> ans;
        priority_queue<long long, vector<long long>, greater<long long>> up;
        priority_queue<long long> down;
        cin >> m;
        int n;
        for(int i = 1; i <= m; ++i){
            cin >> n;
            if(i % 2) {
				down.push(n);
				if(!down.empty() && !up.empty()) {
					if(down.top() > up.top()) {
						up.push(down.top());
						down.pop();
						down.push(up.top());
						up.pop();
					}
				}
                ans.push_back(down.top());
			}
			else {
				up.push(n);
			}
        }
        cout << ans.size() << "\n";
        for(int i = 0; i < ans.size(); ++i){
			cout << ans[i] << " ";
            if(i % 10 == 9) cout << "\n";
		}
		cout << "\n";
    }    
    return 0;
}