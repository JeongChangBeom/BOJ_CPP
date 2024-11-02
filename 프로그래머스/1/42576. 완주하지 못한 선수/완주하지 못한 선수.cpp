#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string,int> m;
    
    for(int i=0;i<participant.size();i++){
        if(m.find(participant[i]) != m.end()){
            m[participant[i]]++;
        }
        else{
            m.insert({participant[i],1});
        }
    }
    
    for(int i=0;i<completion.size();i++){
        if(m[completion[i]]>1){
            m[completion[i]]--;
        }
        else{
            m.erase(completion[i]);
        }
    }
    
    answer = m.begin()->first;
    
    return answer;
}