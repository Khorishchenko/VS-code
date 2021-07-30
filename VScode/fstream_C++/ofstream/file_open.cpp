#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream file1;
    std::ofstream file2;

    file1.open("/Users/sergejhorisenko/Desktop/VS-code/VScode/fstream_C++/myfile.txt");
    file2.open("/Users/sergejhorisenko/Desktop/VS-code/VScode/fstream_C++/myf.txt");

    if (file1.is_open() && file2.is_open())
        std::cout << "Files are open !!!" << std::endl;
    else
        std::cout << "Files are not Open, Bed !" << std::endl;

    std::string text;
    std::string buf;

    while(!file1.eof()){
        getline(file1, buf);
        text = buf + '\n' + text;
    }


    file2 << text;


    file1.close();
    file2.close();


    return 0;

}