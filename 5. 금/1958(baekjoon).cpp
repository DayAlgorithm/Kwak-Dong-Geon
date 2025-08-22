#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

string str1, str2, str3;
int cache[101][101][101];

int dp(int idx, int before1, int before2){
    if(idx == str1.length()) return 0;

    int &ret = cache[idx][before1][before2];
    if(ret != -1) return ret;

    for(int i = before1; i < str2.length(); ++i){
        if(str1[idx] == str2[i]){
            for(int j = before2; j < str3.length(); ++j){
                if(str2[i] == str3[j]){
                    ret = (ret, dp(idx + 1, i + 1, j + 1) + 1);
                    break;
                }
            }
            break;
        }
    }
    ret = max(ret, dp(idx + 1, before1, before2));
    return ret;
}

int main(){
    FastIO;
    cin >> str1 >> str2 >> str3;
    memset(cache, -1, sizeof(cache));
    cout << dp(0, 0, 0);
    return 0;
}