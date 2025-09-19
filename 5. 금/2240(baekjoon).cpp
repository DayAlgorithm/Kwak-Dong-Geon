#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int t, w;
int  ceche[1001][31][3];
int tree[1001];

int fall(int idx, int now, int pos){
    if(now > w) return -INT_MAX;
    if(idx == t) return 0;

    int &ret = ceche[idx][now][pos];
    if(ret != -1) return ret;

    int eat;
    if(tree[idx] == pos) eat  = 1;
    else eat = 0;

    if(pos == 1){
        if(tree[idx] == pos + 1) eat  = 1;
        else eat = 0;
        ret = max(ret, fall(idx + 1, now + 1, 2) + eat);
    }
    else if(pos == 2){
        if(tree[idx] == pos  - 1) eat  = 1;
        else eat = 0;
        ret = max(ret, fall(idx + 1, now + 1, 1) + eat);
    }
    if(tree[idx] == pos) eat  = 1;
    else eat = 0;
    return ret = max(ret, fall(idx + 1, now, pos) + eat);
}

int main(){
    FastIO;
    cin >> t >> w;
    for(int i = 0; i < t; i++){
        cin >> tree[i];
    }
    memset(ceche, -1, sizeof(ceche));
    cout << fall(0, 0, 1);
    return 0;
}