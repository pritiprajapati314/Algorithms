#include<iostream>
#include<string>
#include<stack>
#include <typeinfo>

using namespace std;
stack <string> storded;

string infixToPostfix(string infix){

    string result = "";
    string s = "";
    for(int i = 0; i<infix.size(); i++){
        if(infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*'){
            s = infix[i];
            storded.push(s);
        }
        else if(infix[i] == ')'){
            while(!storded.empty()){
                result += storded.top(); storded.pop();
            }
            //storded.push(result);
        }
        else if(infix[i] != '('){
            result += infix[i];
        }
        if(i+1 += infix.size()){
            while(!storded.empty()){
                result += storded.top(); storded.pop();
            }
        }
    }
    return result;
}


int main(){
    string infix = "k+m*(l-n)*r+o";
    string postfix = infixToPostfix(infix);  
    cout<<postfix;
}

