#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) { 
    unordered_map<string,bool> m;
    
    for(int i=0;i<phone_book.size();i++){
        m.insert({phone_book[i],true});
    }
    
    for(int i=0;i<phone_book.size();i++){
        for(int j=0;j<phone_book[i].size()-1;j++){
            if(m[phone_book[i].substr(0,1+j)]){
                return false;
            }
        }
    }
    
    return true;
}