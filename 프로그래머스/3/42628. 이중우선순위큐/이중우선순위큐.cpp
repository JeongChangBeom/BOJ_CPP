#include <string>
#include <vector>
#include <string>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    multiset<int> ms;

    for(int i=0;i<operations.size();i++){        
        string str = operations[i];
    
        string temp = "";
        string cmd;
        int num;
    
        for(int j=0;j<str.size();j++){
            if(str[j] == ' '){
                cmd = temp;
                temp = "";
            }   
            else{
                temp += str[j];
            }
        }
        
        num = stoi(temp);
    
        if(cmd == "I"){
            ms.insert(num);
        }   
        else if(cmd == "D" && !ms.empty()){
            if(num == 1){
                ms.erase(*ms.rbegin());
            }
            else if(num == -1){
                ms.erase(*ms.begin());
            }
        }
    }

    if(ms.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(*ms.rbegin());
        answer.push_back(*ms.begin());
    }

    return answer;
}