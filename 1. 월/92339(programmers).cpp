#include <bits/stdc++.h>

using namespace std;

string change(int n, int k){
    string ret = "";
    while(n > 0){
        int mod = n % k;
        n /= k;
        ret += to_string(mod);
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

bool isPrime(long long num){
    if(num < 2) return false;
    if(num == 2) return true;
    if(num % 2 == 0) return false;
    
    for(long long i = 3; i * i <= num; i += 2){
        if(num % i == 0) return false;
    }
    return true;
}

int solution(int n, int k){
    int ans = 0;
    string s = change(n, k);
    
    string temp = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '0'){
            if(temp != "" && temp != "0"){
                long long num = stoll(temp);
                if(isPrime(num)) ans++;
            }
            temp = "";
        } 
        else temp += s[i];
    }
    
    if(temp != "" && temp != "0"){
        long long num = stoll(temp);
        if(isPrime(num)) ans++;
    }
    
    return ans;
}
