#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int,int>> q;
    priority_queue<int> pq;
    
    for(int i=0;i<priorities.size();i++){
        q.push({priorities[i],i});
        pq.push(priorities[i]);
    }
    
    int count = 1;
    
    while(true){
        pair<int,int> front = q.front();
        q.pop();
        
        if(front.first == pq.top()){
            if(front.second == location){
                answer = count;
                break;
            }
            else{
                count++;
                pq.pop();
            }
        }
        else{
            q.push({front.first,front.second});
        }
    }
    
    return answer;
}