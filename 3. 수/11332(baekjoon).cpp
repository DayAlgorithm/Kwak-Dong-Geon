#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main(){
    FastIO;
    int c;
    cin >> c; 
    while(c--){
        string str;
        long long n, t, l;
        cin >> str >> n >> t >> l;
        l *= 100000000;
        bool tle = false;
        
        if(str == "O(N)"){
            long long T = (long long)n * t;
            if(T > l) tle = true;
        }
        else if(str == "O(N^2)"){
            if(n > 31622){
                tle = true;
            } 
            else{
                long long T = (long long)n * n * t;
                if(T > l) tle = true;
            }
        }
        else if(str == "O(N^3)"){
            if(n > 1000){
                tle = true;
            } 
            else{
                long long T = (long long)n * n * n * t;
                if(T > l) tle = true;
            }
        }
        else if(str == "O(2^N)"){
            if(n >= 30){
                tle = true;
            } 
            else{
                long long T = t;
                for(int i = 0; i < n; ++i){
                    T *= 2;
                    if(T > l){
                        tle = true;
                        break;
                    }
                }
            }
        }
        else if(str == "O(N!)"){
            if(n >= 13){
                tle = true;
            } 
            else{
                long long T = t;
                for(int i = 1; i <= n; ++i){
                    T *= i;
                    if(T > l){
                        tle = true;
                        break;
                    }
                }
            }
        }
        if(tle) cout << "TLE!\n";
        else cout << "May Pass.\n";
    }
    return 0;
}