#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
      
    set<int> s;
    
    for(int i=0;i<elements.size();i++){
        int sum = 0;
        for(int j=i;j<elements.size()+i;j++){
            sum += elements[j%elements.size()];
            s.insert(sum);
        }
    }
    
    answer = s.size();
    
    return answer;
}