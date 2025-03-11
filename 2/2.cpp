#include <iostream>
#include <regex>
#include <algorithm>
#include <fstream>
#include <vector>
std::regex word_regex{"(\\w+)"};
int main(){
    {
        std::fstream input{"input.txt", std::ios::in};
        std::fstream output{"output_1.txt", std::ios::out};
        if(!(input.is_open() && output.is_open())){
            throw std::logic_error{"Can't open file."};
        }
        while (!input.eof())
        {
            std::string line;
            std::getline(input, line);
            auto result_begin = std::sregex_iterator(line.begin(), line.end(), word_regex);
            auto result_end = std::sregex_iterator();
            std::vector<std::string> words;
            for(auto i = result_begin; i != result_end; i++){
                words.push_back(i->str());
            }
            std::sort(words.begin(), words.end());
            for(auto& i : words){
                output << i << " ";
            }
            output << std::endl;
        }
        input.close();
        output.close();
    }
    {
        std::fstream input{"input.txt", std::ios::in};
        std::fstream output{"output_2.txt", std::ios::out};
        if(!(input.is_open() && output.is_open())){
            throw std::logic_error{"Can't open file."};
        }
        std::vector<std::string> lines;
        while (!input.eof())
        {
            std::string line;
            std::getline(input, line);
            lines.push_back(line);
        }
        std::sort(lines.begin(), lines.end());
        for(auto& i : lines){
            output << i << std::endl;
        }
        input.close();
        output.close();
    }
}
