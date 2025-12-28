#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int a, b, c;
bool visited[201][201];
set<int> ans;

void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    
    while(!q.empty()) {
        int A = q.front().first, B = q.front().second, C = c - A - B;
        q.pop();
        
        if(!A) ans.insert(C);
        
        int water = min(A, b - B);
        int nextA = A - water, nextB = B + water;
        if(!visited[nextA][nextB]) {
            visited[nextA][nextB] = true;
            q.push({nextA, nextB});
        }
        
        water = min(A, c - C);
        nextA = A - water;
        int nextC = C + water;
        if(!visited[nextA][B]) {
            visited[nextA][B] = true;
            q.push({nextA, B});
        }
        
        water = min(B, a - A);
        nextA = A + water;
        nextB = B - water;
        if(!visited[nextA][nextB]) {
            visited[nextA][nextB] = true;
            q.push({nextA, nextB});
        }
        
        water = min(B, c - C);
        nextB = B - water;
        nextC = C + water;
        if(!visited[A][nextB]) {
            visited[A][nextB] = true;
            q.push({A, nextB});
        }
        
        water = min(C, a - A);
        nextA = A + water;
        nextC = C - water;
        if(!visited[nextA][B]) {
            visited[nextA][B] = true;
            q.push({nextA, B});
        }
        
        water = min(C, b - B);
        nextB = B + water;
        nextC = C - water;
        if(!visited[A][nextB]) {
            visited[A][nextB] = true;
            q.push({A, nextB});
        }
    }
}

int main() {
    FastIO;
    cin >> a >> b >> c;
    
    bfs();
    
    for(int x : ans) {
        cout << x << ' ';
    }
    
    return 0;
}
