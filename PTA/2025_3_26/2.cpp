#include <iostream>
#include <stack>
#include <string>
int main(){
    std::stack<char> operatorStack;
    std::string str;
    getline(std::cin, str);
    try{
        for (auto i : str)
        {
            switch (i)
            {
            case '(':
                operatorStack.push('(');
                break;
            case ')':
                if(operatorStack.size() > 0 && operatorStack.top() == '('){
                    operatorStack.pop();
                }
                else{
                    throw std::logic_error("");
                }
                break;
            case '[':
                operatorStack.push('[');
                break;
            case ']':
                if(operatorStack.size() > 0 && operatorStack.top() == '['){
                    operatorStack.pop();
                }
                else{
                    throw std::logic_error("");
                }
                break;
            default:
                break;
            }
        }
        if(operatorStack.size()){
            throw std::logic_error("");
        }
        std::cout << "Yes";
    }
    catch(std::exception& e){
        std::cout << "No";
        e.what();
    }
}