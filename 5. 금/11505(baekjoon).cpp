#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int n, m, k;
vector<long long> arr, segTree;

long long makeTree(int node, int start, int end){
    if(start == end) return segTree[node] = arr[start];

    int mid = (start + end) / 2;
    return segTree[node] = (makeTree(node * 2, start, mid) * makeTree(node * 2 + 1, mid + 1, end)) % 1000000007;
}

long long multi(int node, int start, int end, int left, int right){
    if(left > end || start > right) return 1;
 
    if(left <= start && end <= right) return segTree[node];
 
    int mid = (start + end) / 2;
    return (multi(node * 2, start, mid, left, right) * multi(node * 2 + 1, mid + 1, end, left, right)) % 1000000007;
}

void update(int node, int start, int end, int idx, long long value){
    if(idx < start || end < idx) return;
 
    if(start == end){
        segTree[node] = value;
        return;
    }
 
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, value);
    update(node * 2 + 1, mid + 1, end, idx, value);
    segTree[node] = (segTree[node * 2] * segTree[node * 2 + 1]) % 1000000007;
}

int main(){
    FastIO;
    cin >> n >> m >> k;
    arr.resize(n + 1);
    segTree.resize(n * 4);
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    makeTree(1, 1, n);
    for(int i = 0; i < m + k; ++i){
        long long a, b, c;
        cin >> a >> b >> c;
        if(a == 1) update(1, 1, n, b, c);
        else cout << multi(1, 1, n, b, c) << "\n";
    }
    return 0;
}