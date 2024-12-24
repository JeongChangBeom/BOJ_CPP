#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool visited[105][105];
int dist[105][105];

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    queue<pair<int,int>> q;
    
    int x = maps.size();
    int y = maps[0].size();
    
    q.push({0,0});
    
    visited[0][0] = true;
    dist[0][0] = 1;
    
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        
        for(int i=0;i<4;i++){
            int next_x = cur.first + dx[i];
            int next_y = cur.second + dy[i];
            
            if(next_x >= 0 && next_x < x && next_y >= 0 && next_y < y && maps[next_x][next_y] == 1 && !visited[next_x][next_y]){
                visited[next_x][next_y] = true;
                q.push({next_x,next_y});
                dist[next_x][next_y] = dist[cur.first][cur.second]+1;
            }
        }
    }
    
    if(!visited[x-1][y-1]){
        answer = -1;
    }
    else{
        answer = dist[x-1][y-1];
    }
    
    
    return answer;
}