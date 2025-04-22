#include<bits/stdc++.h>

using namespace std;

double sum;
int n, level[300001];

int main(){
     cin >> n;
     int except = floor(double(n) * 0.15 + 0.5);
     for(int i = 0; i < n; ++i){
        cin >> level[i];
     }
     sort(level, level + n);
     for(int i = except; i < n - except; ++i){
        sum += double(level[i]);
     }
     sum = floor(sum/(n - 2*except) + 0.5);
     //n이 0인경우 이상한 값이 나온다.
     if(!n) cout << 0 << endl;
     else cout << int(sum) << endl;
}