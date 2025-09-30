#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m;
map<int, int> problem_level;
set<pair<int, int>> problems;

int main(){
    FastIO;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int p, l;
        cin >> p >> l;
        problem_level[p] = l;
        problems.insert({l, p});
    }

    cin >> m;
    for(int i = 0; i < m; ++i){
        string order;
        cin >> order;

        if(order == "add"){
            int p, l;
            cin >> p >> l;
            if(problem_level.find(p) != problem_level.end()){
                problems.erase({problem_level[p], p});
            }
            problem_level[p] = l;
            problems.insert({l, p});
        } 
        else if(order == "solved"){
            int p;
            cin >> p;
            if(problem_level.find(p) != problem_level.end()){
                problems.erase({problem_level[p], p});
                problem_level.erase(p);
            }
        } 
        else{
            int x;
            cin >> x;
            if(x == 1){
                cout << prev(problems.end())->second << "\n";
            } else {
                cout << problems.begin()->second << "\n";
            }
        }
    }
    return 0;
}
