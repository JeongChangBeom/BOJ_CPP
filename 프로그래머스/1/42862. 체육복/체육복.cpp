#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    map<int,int> m;
    
    for(int i=1;i<=n;i++){
        m.insert({i,0});
    }
    
    for(int i=0;i<lost.size();i++){
        m[lost[i]]--;
    }
    
    for(int i=0;i<reserve.size();i++){
        m[reserve[i]]++;
    }
    
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second < 0){
            if(prev(it)->second == 1){
                it->second++;
                prev(it)->second--;
            }
            else if(next(it)->second == 1){
                it->second++;
                next(it)->second--;
            }
        }
    }
    
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second >= 0){
            answer++;
        }
    }
    
    return answer;
}