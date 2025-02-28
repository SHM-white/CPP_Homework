#include <iostream>
#include <exception>
#include <regex>
int main(){
    try{
        std::string input;
        std::cin >> input;
        //find only one "@"
        {
            int index = 0;
            bool found = false;
            while (index != -1)
            {
                index = input.find('@', index + 1);
                if(index != -1){
                    if(found){
                        throw std::logic_error{"More than one \'@\'."};
                    }
                    if(index > 20){
                        throw std::logic_error{"String too long before \'@\'."};
                    }
                    found = true;
                }
                if(index == 0){
                    throw std::logic_error{"Short string before \'@\'."};
                }
            }
            if(!found){
                throw std::logic_error{"\'@\' not found."};
            }
        }
        //find '.' after '@'
        {
            int index = input.find('@');
            int index2 = input.find('.', index);
            if (index2 == -1)
            {
                throw std::logic_error{"\'.\' not found."};
            }
            if (index2 - index > 20)
            {
                throw std::logic_error{"String after \'@\' before \'.\' too long."};
            }
            if (input.length() - index2 > 20)
            {
                throw std::logic_error{""};
            }
        }
        //count '.'
        {
            int count = 0;
            for(auto i : input){
                if(i == '.'){
                    count++;
                }
            }
            if(count > 3){
                throw std::logic_error{"Too much \'.\'."};
            }
        }
        //find illegal characters
        {
            for(auto& i : input){
                if(!((std::tolower(i) >= 'a' && std::tolower(i) <= 'z') || (i >= '0' && i <= '9') || i == '@' || i == '.' || i == '_')){
                    throw std::logic_error{std::string{"Illegal character: "} + std::string{i} + std::string{"."}};
                }
            }
        }
    }
    catch(std::logic_error& ex){
        std::cout << ex.what() << std::endl;
    }
}