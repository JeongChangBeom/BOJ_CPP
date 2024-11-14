#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int one[5] = {1,2,3,4,5};
int two[8] = {2,1,2,3,2,4,2,5};
int three[10] = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int one_count = 0;
    int two_count = 0;
    int three_count = 0;
    
    for(int i=0;i<answers.size();i++){
        if(answers[i] == one[i%5]){
            one_count++;
        }
        if (answers[i] == two[i%8]){
            two_count++;
        }
        if (answers[i] == three[i%10]){
            three_count++;
        }
    }
    
    int temp = max(one_count,max(two_count,three_count));
    
    if(temp == one_count){
        answer.push_back(1);
    }
    if(temp == two_count){
        answer.push_back(2);
    }
    if(temp == three_count){
        answer.push_back(3);
    }
    
    return answer;
}