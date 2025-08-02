#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

int n, q;
vector<long long> segTree;

void makeTree(int node, int start, int end){
    segTree[node] = 0;
    if(start == end) return;
    int mid = (start + end) / 2;
    makeTree(node*2, start, mid);
    makeTree(node*2 + 1, mid + 1, end);
}

long long query(int node, int start, int end, int left, int right){
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return segTree[node];
    int mid = (start + end) / 2;
    return query(node*2, start, mid, left, right) + query(node*2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, long long value) {
    if(idx < start || end < idx) return;
    if(start == end) {
        segTree[node] += value;
        return;
    }
    int mid = (start + end) / 2;
    update(node*2, start, mid, idx, value);
    update(node*2 + 1, mid+1, end, idx, value);
    segTree[node] = segTree[node*2] + segTree[node*2 + 1];
}

int main() {
    FastIO;
    cin >> n >> q;
    segTree.resize(n*4, 0);
    makeTree(1, 1, n);
    for(int i = 0; i < q; ++i){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if(a == 1) update(1, 1, n, b, c); 
        else cout << query(1, 1, n, b, c) << '\n';
    }
    return 0;
}
