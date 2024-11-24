#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    
    while(true){
        if(pq.size() == 1){
            if(pq.top() >= K){
                return answer;
            }
            else{
                return -1;
            }
        }
        if(pq.top() >= K){
            return answer;
        }
        
        int food_1 = pq.top();
        pq.pop();
        int food_2 = pq.top();
        pq.pop();
        
        pq.push(food_1 + (food_2*2));
        answer++;
    }
}