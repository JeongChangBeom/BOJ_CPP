#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(),times.end());
    
    long long start = 1;
    long long end = n * (long long)times[times.size()-1];
    
    while(start <= end){
        long long mid = (start+end)/2;
        long long count = 0;
        
        for(int i=0;i<times.size();i++){
            count += mid/(long long)times[i];
        }
        
        if(count >= n){
            end = mid-1;
            answer = mid;
        }
        else{
            start = mid+1;
        }
    }
    
    return answer;
}