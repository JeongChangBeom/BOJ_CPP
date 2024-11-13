#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {   
    int h = 0;
    int w = 0;
    
    for(int i=0;i<sizes.size();i++){
        if(sizes[i][0] > sizes[i][1]){
            h = max(h,sizes[i][0]);
            w = max(w,sizes[i][1]);
        }
         else{
            h = max(h,sizes[i][1]);
            w = max(w,sizes[i][0]);
        }
    }

    return h*w;
}