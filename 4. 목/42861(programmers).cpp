#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unionParent(int a, int b) {
    a = find(a);
    b = find(b);

    if (a < b) parent[b] = a;
    else parent[a] = b;
}

bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int ans = 0;
    
    parent.resize(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    sort(costs.begin(), costs.end(), cmp);
    
    for (int i = 0; i < costs.size(); i++) {
        int start = costs[i][0];
        int end = costs[i][1];
        int cost = costs[i][2];
        
        if (find(start) != find(end)) {
            unionParent(start, end);
            ans += cost;
        }
    }
    
    return ans;
}