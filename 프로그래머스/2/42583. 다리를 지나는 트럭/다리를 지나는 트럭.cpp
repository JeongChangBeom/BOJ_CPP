#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> q;
    
    int total_weights = 0;
    int i = 0;
    
    while(true){  
        if(i == truck_weights.size()){
            answer += bridge_length;
            break;
        }
        
        answer++;
        
        if(q.size() == bridge_length){
            total_weights -= q.front();
            q.pop();
        }
        
        if(total_weights+truck_weights[i] <= weight){
            q.push(truck_weights[i]);
            total_weights += truck_weights[i];
            i++;
        }
        else{
            q.push(0);
        }
    }
    
    return answer;
}