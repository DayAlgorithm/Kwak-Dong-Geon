#include <bits/stdc++.h>
using namespace std;
 
 
bool checkIn(int y, int x){
    return (y < 5 && y >= 0 && x < 5 && x >= 0);
}
 
bool check(int y, int x, vector<string>& place){
 
    if(place[y][x] != 'P') return true;
 
    if(checkIn(y + 1,x) && place[y + 1][x] == 'P') return false;
    if(checkIn(y, x + 1) && place[y][x + 1] == 'P') return false;
    if(checkIn(y + 2, x) && place[y + 2][x] == 'P' && place[y + 1][x] !='X') return false;
    if(checkIn(y, x + 2) && place[y][x + 2] == 'P' && place[y][x + 1] !='X') return false;

    if(checkIn(y + 1, x + 1) && place[y + 1][x + 1] == 'P'){
        if(place[y + 1][x] != 'X') return false;
        if(place[y][x + 1] != 'X') return false;
    }
    if(checkIn(y + 1,x - 1) && place[y + 1][x - 1] == 'P'){
        if(place[y][x - 1] != 'X') return false;
        if(place[y + 1][x] != 'X') return false;        
    }
    return true;
}
 
bool checkPlace(vector<string>& place){
    for(int y = 0; y < 5; ++y){
        for(int x = 0; x < 5; ++x){
                if(!check(y, x, place)){
                    return false;
                }
        }
    }
    return true;
}
 
 
vector<int> solution(vector<vector<string>> places) {
    vector<int> ans;
    for(int i = 0; i < 5; ++i){
        if(!checkPlace(places[i])) ans.push_back(0);
        else ans.push_back(1);
    }
 
 
    return ans;
}