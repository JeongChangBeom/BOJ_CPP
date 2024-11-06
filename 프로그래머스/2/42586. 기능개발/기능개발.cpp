#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;
    
    for(int i=0;i<progresses.size();i++){
        int count = 0;
        
        while(true){
            if(progresses[i]<100){
                count++;
                progresses[i]+= speeds[i];
            }
            else{
                q.push(count);
                break;
            }
        }
    }
    
    while(!q.empty()){
        int day = q.front();
        q.pop();
        
        int result = 1;
        
        while(!q.empty() && q.front() <= day){
            result++;
            q.pop();
        }
        answer.push_back(result);
    }
    
    return answer;
}