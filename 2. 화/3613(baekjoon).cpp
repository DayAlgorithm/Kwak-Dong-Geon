//3613
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string str, ans;
bool flag1, flag2;

int main(){
    FastIO;
    cin >> str;
    for(int i = 0; i < str.size(); ++i){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            flag1 = true;
            if(flag2) break;
            if(i == 0){
                flag2 = true;
                break;
            }
            ans.push_back('_');
            ans.push_back(tolower(str[i]));
        }
        else if(str[i] == '_'){
            flag2 = true;
            if(flag1) break;
            if(i == 0){
                flag1 = true;
                break;
            }
            i++;
            if(i < str.size()){
                if(str[i] == '_' || (str[i] >= 'A' && str[i] <= 'Z')){
                    flag1 = true;
                    break;
                }
                ans.push_back(toupper(str[i]));
            }
            else{
                flag1 = true;
                break;
            }
        }
        else ans.push_back(str[i]);
    }
    if(flag1 && flag2) cout << "Error!";
    else cout << ans;
    return 0;
}