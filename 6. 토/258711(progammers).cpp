#include <bits/stdc++.h>
using namespace std;

int in[1000001], out[1000001];
bool visited[1000001];
vector<vector<int>> adj(1000001);
int root;

int bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(!out[now]) return 2; //나가는 간성이 없는 경우 : 막대
        if(out[now] >= 2) return 3; //나가는 간선이 2개 이상인 경우 : 팔자
        for(int i = 0; i < out[now]; ++i){
            int next = adj[now][i];
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return 1;   //막대, 팔자 모두 아닌 경우 : 도넛
}

//외부 정점 찾기
void findRoot(const vector<vector<int>>& edges){
    for(int i = 0; i < edges.size(); ++i){  //in/out 간선의 개수 저장
        out[edges[i][0]]++;
        in[edges[i][1]]++;
        adj[edges[i][0]].push_back(edges[i][1]);   //tree 인접 리스트 표현
    }
    for(int i = 1; i <= 1000000; ++i){  //in을 0, out은 2이상인 노드가 루트
        if(!in[i] && out[i] >=2){
            root = i;
            break;
        }
    }
}

//종류에 따른 트리 개수 세기
void cntTree(vector<int>& answer, const vector<vector<int>>& edges){
    findRoot(edges);
    answer[0] = root;
    for(int i = 0; i < out[root]; ++i){
        switch(bfs(adj[root][i])){  //tree 종류에 따라 개수 추가
            case 1 :    //도넛
                answer[1]++;
                break;
            case 2 :    //막대
                answer[2]++;
                break;
            case 3 :    //팔자
                answer[3]++;
                break;
        }
    }
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);
    cntTree(answer, edges);
    return answer;
}