#include<iostream>
#include<string>
#include<stack>
#include <typeinfo>

using namespace std;
stack <char> storded;

int priority(char a){
    switch(a){
        case '+':
            return 1;
        case '-':
            return 1;
        case '/':
            return 2;
        case '*':
            return 2;
    }
}

string infixToPostfix(string infix){

    string result = "";
    for(int i = 0; i<infix.size(); i++){
        if(i == infix.size()-1){
            while(!storded.empty()){
                if(storded.top() != '(')
                    result += storded.top();
                storded.pop();
            }
        }else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*' || infix[i] == '('){
            if(storded.empty())
                storded.push(infix[i]);
            else if(storded.top() == '(' || priority(storded.top()) < priority(infix[i]))
                storded.push(infix[i]);
            else {
                while(!storded.empty() && priority(storded.top()) >= priority(infix[i]) && storded.top() != '('){
                    result += storded.top(); storded.pop();
                    }
                storded.push(infix[i]);
            }
        }
        else if(infix[i] == ')'){
            while(!storded.empty() || storded.top() == '('){
                result += storded.top(); storded.pop();
            }
            storded.pop();
        }
        else {
            result += infix[i];
        }
    }
    return result;
}


int main(){
    string infix = "b*c-d+e/f/(g+h)";
    string postfix = infixToPostfix(infix);  
    cout<<postfix;
}

