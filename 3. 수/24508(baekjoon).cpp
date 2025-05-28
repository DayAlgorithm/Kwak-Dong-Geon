#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n, k, t;
vector<int> a;

bool check(){
    int left = 0, right = n - 1;
    while(left < right){
        if(!a[right]){
            right--;
            continue;
        }
        if(!a[left]){
            left++;
            continue;
        }
        int need = k - a[right];
        if(t < need) return false;
        if(need >= a[left]){
            a[right] += a[left];
            t -= a[left];
            left++;
        }
        else if(need < a[left]){
            a[left] -= need;
            t -= need;
            right--;
        }
    }
    if(a[right] == k || !a[right]) return true;
    else return false;
}

int main(){
    FastIO;
    cin >> n >> k >> t;
    a = vector<int>(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if(check()) cout << "YES";
    else cout << "NO";
    return 0;
}