#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    stack<char> s;
    
    int count = 0;
    
    for(int i=0;i<number.size();i++){
        char num = number[i];
        
        while(!s.empty() && count < k){         
            if(s.top() < num){
                s.pop();
                count++;
            }
            else{
                break;
            }
        }
        s.push(num);
    }
    
    while(s.size() != number.size()-k){
        s.pop();
    }
    
    while(!s.empty()){
        answer += s.top();
        s.pop();
    }
    
    reverse(answer.begin(),answer.end());
    
    return answer;
}