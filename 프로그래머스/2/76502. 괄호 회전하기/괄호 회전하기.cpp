#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string str) {
    int answer = 0;
    
    for(int i=0;i<str.size();i++){
        stack<char> s;
        
        bool check = false;
        
        for(int j=0;j<str.size();j++){
            if(str[j] == '(' || str[j] == '{' || str[j] == '['){
                s.push(str[j]);
                
                check = true;
            }
            else if (str[j] == ')'){
                if(s.top() == '('){
                    s.pop();
                }
            }
            else if (str[j] == '}'){
                if(s.top() == '{'){
                    s.pop();
                }
            }
            else if (str[j] == ']'){
                if(s.top() == '['){
                    s.pop();
                }
            }
        }
        
        if(s.empty() && check){
            answer++;
        }
        
        str += str[0];
        str.erase(str.begin());
    }
    
    return answer;
}