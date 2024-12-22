#include <string>
#include <vector>

using namespace std;

bool visited[201];

void DFS(int v, int n, vector<vector<int>> graph){
    visited[v] = true;
    
    for(int i=0;i<n;i++){
        if(!visited[i] && graph[v][i] == 1){
            DFS(i,n,graph);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            DFS(i,n,computers);
            answer++;
        }
    }
    
    return answer;
}