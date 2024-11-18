#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int x, int y){
    return x > y;
}

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(),citations.end(),compare);
    
    for(int i=0;i<citations.size();i++){
        if(citations[i] >= i+1){
            answer = i+1;
        }
    }
    
    return answer;
}