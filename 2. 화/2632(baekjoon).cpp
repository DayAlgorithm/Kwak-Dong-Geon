#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int s, m, n, ans;

void cnt(int k, vector<int>& arr, vector<int>& arrSum){
    for(int i = 1; i <= k; ++i){
        int sum = 0;
        for(int j = 0; j < i; ++j) sum += arr[j];
        arrSum[sum]++;
        if(sum == s) ans++;
        
        if(i == k) break;
        for(int j = 1; j < k; j++){  //원형 부분합 구현
            sum -= arr[j - 1];
            sum += arr[(j + i - 1) % k];  //슬라이딩 윈도우 기법
            arrSum[sum]++;
            if(sum == s) ans++;
        }
    }
}

int main(){
    FastIO;
    cin >> s >> m >> n;
    vector<int> a, b;
    vector<int> aSum, bSum;
    a = vector<int>(m, 0);
    b = vector<int>(n, 0);
    aSum = vector<int>(2000001, 0);
    bSum = vector<int>(2000001, 0);
    ans = 0;
    
    for(int i = 0; i < m; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    
    cnt(m, a, aSum);
    cnt(n, b, bSum);
    
    for(int i = 1; i < s; ++i){
        int j = s - i;
        ans += aSum[i] * bSum[j];
    }
    
    cout << ans;
    return 0;
}
