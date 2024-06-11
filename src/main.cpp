#include <iostream>
#include "tree.h"

/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
*/
int main()
{
    AVLTree students;
    std::string argument;
    std::string num_arguments;// need this, throws error if i use argument in the for loop definition
    std::getline(std::cin, num_arguments);

    for(int i = 0; i < std::stoi(num_arguments); i++) // run the amount of arguments given
    {
        std::getline(std::cin, argument);
        if(argument == "printInorder") {
            students.printInorder();
            continue;
        }
        else if(argument == "printPreorder")
        {
            students.printPreorder();
            continue;
        }
        else if(argument == "printPostorder")
        {
            students.printPostorder();
            continue;
        }
        else if(argument == "printLevelCount")
        {
            students.levelcount();
            continue;
        }
        else
        {
            std::regex exp = std::regex("removeInorder\\s([0-9]+)"); // regex for removeinorder
            std::smatch args;
            if(std::regex_match(argument, args, exp))
            {
                students.removeInorder(std::stoi(args[1].str()));
                continue;

            }
            exp = std::regex("insert\\s\"([a-zA-Z\\s]*)\"\\s([0-9]{8})");//regex for insert
            if(std::regex_match(argument, args, exp))
            {
                students.insert(args[1].str(), args[2].str());
                continue;
            }
            exp = std::regex("remove ([0-9]{8})");//regex for remove ID

            if(std::regex_match(argument, args, exp))
            {
                students.remove(args[1].str());
                continue;
            }

            exp = std::regex("search\\s([0-9]{8})");//regex for search ID
            if(std::regex_match(argument, args, exp))
            {
                students.name_from_id(args[1]);
                continue;
            }
            exp = std::regex("search\\s([a-zA-Z\\s]*)"); //regex for search name
            if(std::regex_match(argument, args, exp))
            {
                students.id_from_name(args[1]);
                continue;
            }
            std::cout << "unsuccessful" << std::endl;
        }
    }

}
