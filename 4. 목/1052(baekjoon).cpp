#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n, k, ans;

int main(){
	FastIO;
	cin >> n >> k;

	if (k >= n) {
		cout << 0;
	} else {
		while (true) {
			int cnt = 0, a = n;
			while (a > 0) {
				if (a % 2 == 0) {
					a /= 2;
				} else {
					a /= 2;
					cnt++;
				}

			}
			if (k >= cnt) {
				break;
			}
			n++;
			ans++;
		}
		cout << ans;
	}
	return 0;
}