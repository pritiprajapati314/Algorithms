#include<iostream>
#include<string>
#include<stack>

using namespace std;

string postfixToInfix(string postfix){

    string result = "";
    string temp1 = "", temp2 = "";
    stack<string> storeded;
    for(int i = 0; i<postfix.size(); i++){
        if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/'){
            temp1 = storeded.top(); storeded.pop();
            temp2 = storeded.top(); storeded.pop();
            temp2 += postfix[i] + temp1;
            storeded.push(temp2);
        }
        else {
            temp1 = postfix[i];
            storeded.push(temp1);
        }
    }
    return storeded.top();
}

int main(){
    string postfix = "ABCD*/-E+";
    string infix = postfixToInfix(postfix);
    cout<<infix;
}