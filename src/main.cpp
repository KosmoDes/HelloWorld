#include <iostream>
#include <fstream>
#include <string>
#include <map>

std::map<std::string, int>  commands = {std::pair<std::string, int>("HelloWorld!", 0)};
std::string keywords[] = {"Hello", "World!"};

void HelloWorld();

void useCommand(int command) {
    switch (command)
    {
    case 0:
        HelloWorld();
        break;
    
    default:
        break;
    }
}

void parse(char filename[]) {
    std::ifstream input(filename);
    std::string word;
    bool main = 0;
    while(true) {
        input >> word;
        if(word == keywords[0] && !main) {
            input >> word;
            if(word == "World()") {
                main = 1;
                continue;
            }
        }
        else if(main && word != keywords[1]) {
            useCommand(commands[word]);
        }
        else if(word == keywords[1]) {
            break;
        }
    }
}

int main(int arc, char *argv[]) {
    if(arc > 2) {
        std::cout << "ERROR: TOO MANY ARGUMENTS\n";
        return 0;
    }
    if(arc < 2) {
        std::cout << "ERROR: TOO LOW ARGUMENTS\n";
        return 0;
    }
    std::string expansion = "";
    for(char* ch = argv[1] + strlen(argv[1]) - 1; ch != argv[1] - 1; ch--) {
        expansion += (*ch);
        if((*ch) == '.') break;
    }
    if(expansion != "wlh.") {
        std::cout << "ERROR: INCORRECT EXPANSION\n";
        return 0;
    }
    parse(argv[1]);
}

void HelloWorld(){
    std::cout << "Hello World!\n";
}