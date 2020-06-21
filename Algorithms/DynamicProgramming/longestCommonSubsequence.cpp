#include <iostream>
#include <vector> 
#include <string>

using namespace std;

int maximum(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int longestCommonSequence(string first, string second, int lenF, int lenS){
    if(lenF == 0 || lenS == 0 ){
        return 0; 
    }

    if(first[lenF-1] == second[lenS -1]){
        cout<<first[lenF-1]<<" ";
        return (1 + longestCommonSequence(first, second, lenF-1, lenS-1));
    }
    else{
        return maximum(longestCommonSequence(first, second, lenF-1, lenS),
                   longestCommonSequence(first, second, lenF, lenS-1));
    }
}

void testCaseLCS(){
    string first = "babbab";
    string second = "abaaba";
    vector<string>sequence;
   
    cout<<longestCommonSequence(first, second, first.size(), second.size());
}


int main(){
    testCaseLCS();
    return 0;
}