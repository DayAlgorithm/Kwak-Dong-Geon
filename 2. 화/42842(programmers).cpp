#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    int x = 0.5 * ((2 + brown / 2) + sqrt((2 + brown / 2) 
            * (2 + brown / 2) - 4 * brown - 4 * yellow));
    int y =  0.5 * brown - x + 2;
    return {x, y};
}