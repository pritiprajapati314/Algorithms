#include<iostream>
#include<string>
#include<stack>
#include <typeinfo>

using namespace std;
stack <char> storded;

string infixToPostfix(string infix){

    string result = "";
    string s = "";
    for(int i = 0; i<infix.size(); i++){
        if(infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*'){
            storded.push(infix[i]);
        }
        else if(infix[i] == ')'){
            while(!storded.empty()){
                result += storded.top(); storded.pop();
            }
        }
        else if(infix[i] != '('){
            result += infix[i];
        }
        if(i+1 == infix.size()){
            while(!storded.empty()){
                result += storded.top(); storded.pop();
            }
        }
    }
    return result;
}


int main(){
    string infix = "k+m*(l-n)/r+o";
    string postfix = infixToPostfix(infix);  
    cout<<postfix;
}

