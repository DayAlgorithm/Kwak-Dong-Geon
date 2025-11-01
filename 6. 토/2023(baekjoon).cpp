#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

//신기한 소수
int n;
vector<int> prime = {2,3,5,7};

bool isPrime(int num){
    if(num < 2) return false;
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0) return false;
    }
    return true;
}

void dfs(int num, int idx){
    if(idx == n){
        cout << num << '\n';
        return;
    }
    
    for(int i = 1; i <= 9; i += 2){
        int next = num * 10 + i;
        if(isPrime(next)){
            dfs(next, idx + 1);
        }
    }
}

int main(){
    FastIO;
    cin >> n;
    
    for(int i = 0; i < 4; i++){
        dfs(prime[i], 1);
    }
    
    return 0;
}
