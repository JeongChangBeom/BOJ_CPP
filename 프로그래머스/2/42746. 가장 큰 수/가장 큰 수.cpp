#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string x, string y){
    if(x+y > y+x){
        return true;
    }
    else{
        return false;
    }
    
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> result;
    
    for(int i=0;i<numbers.size();i++){
        result.push_back(to_string(numbers[i]));
    }
    
    sort(result.begin(),result.end(),compare);
    
    for(int i=0;i<result.size();i++){
        answer += result[i];
    }
    
    if(answer[0] == '0'){
        answer = "0";
    }
    
    return answer;
}