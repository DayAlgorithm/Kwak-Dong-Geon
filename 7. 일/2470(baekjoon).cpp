#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, l, r;
long long ans = LONG_MAX;
vector<long long> solution;
int main(){
    FastIO;
    cin >> n;
    solution = vector<long long>(n);
    for(int i = 0; i < n; ++i){
        cin >> solution[i];
    }
    sort(solution.begin(), solution.end());
    int left = 0, right = n - 1;
    while(left < right){
        long long sum = solution[left] + solution[right];
        if(abs(sum) < ans){
            ans = abs(sum);
            l = left; r = right;
        }
        if(!sum) break;
        if(sum > 0) right--;
        else left++;
    }
    cout << solution[l] << " " << solution[r];
    return 0;
}