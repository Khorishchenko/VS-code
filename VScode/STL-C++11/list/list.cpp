#include <iostream>
#include <list>
#include <iterator>

int main()
{
    std::list <std::string> listok;
    std::list <int> this_list = {4, 6, 3, 2};

    // pop_front	удалить элемент в начале
    // pop_back	    удалить элемент в конце
    // push_front	добавить элемент в начала
    // push_back	добавить элемент в конец
    // front	    обратится к первому элементу
    // back	        обратиться к последнему элементу
    // insert	    добавить элемент в какое-то место
    // copy	        вывести все элементы списка (и не только)
    // unique	    удалить все дубликаты
    // merge	    добавление другого списка

    std::list <int> mylist;
    std::list <int> listmerge = {7, 8, 9};
 
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < 6; j++) {
        mylist.push_back(i); // добавили 10 элементов
        }
    }
    
    copy(mylist.begin(), mylist.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;                                                
    
    mylist.insert(mylist.end(), 6);  // добавили новый элемент
    
    std::copy (mylist.begin(), mylist.end(), std::ostream_iterator<std::string>(std::cout, " "));  
    std::cout << std::endl;
    
    mylist.unique();  // удалили все дубликаты
    
    std::list <int> :: iterator it; 
    
    for(it = mylist.begin(); it != mylist.end(); it++) { 
        std::cout << (*it) << " ";
    }
    
    mylist.merge(listmerge);  // присвоили список 
    for(it = mylist.begin(); it != mylist.end(); it++) {
        std::cout << (*it) << " ";  
    }
    return 0;




}