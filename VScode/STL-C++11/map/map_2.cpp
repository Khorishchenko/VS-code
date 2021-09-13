#include <iostream>
#include <map>
#include <iterator>

int main()
{
    std::map <std::string, std::string> book = {{"Hi", "Привет"},
                             {"Student", "Студент"},
                             {"!", "!"}};
 
    std::cout << book["Hi"] << std::endl;

    std::map <std::string, std::string> :: iterator it = book.begin();

    for (int i = 0;it != book.end(); it++, i++){
        std::cout << i << ' ' << it->first << " = " << it->second << std::endl;
    }

    std::cout << book.size() << std::endl;

    int num = 1;
    do 
    {
        // int num = 1;
        std::string num_1, num_2;
        std::cout << "Print key: ", getline(std::cin, num_1);
        std::cout << "Print element ", getline(std::cin, num_2);
        book.insert(make_pair(num_1, num_2));

        std::cout << "You want to enter elements of map ?(1)Yes or (0)No: ", std::cin >> num, std::cin.ignore(100, '\n');

    }while(num != 0);


    // std::map <std::string, std::string> :: iterator it = book.begin();

    advance(it, -(book.size()));
    for (int i = 0;it != book.end(); it++, i++){
        std::cout << i << ' ' << it->first << " = " << it->second << std::endl;
    }


    return 0;
}