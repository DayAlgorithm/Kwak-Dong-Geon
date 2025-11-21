#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int main(){
    FastIO;
    long long x;
    int n;
    vector<long long> l;
    while(cin >> x >> n){
        l.resize(n);
        x *= 10000000;
        for(int i = 0; i < n; ++i){
            cin >> l[i];
        }
        sort(l.begin(), l.end());
        int left = 0, right = n - 1;
        while(left < right){
            if(x == l[left] + l[right]){
                cout << "yes " << l[left] << " " << l[right] << "\n";
                break;
            }
            else if(x < l[left] + l[right]) --right;
            else ++left;
        }
        if(left >= right) cout << "danger\n";
    }
    return 0;
}
